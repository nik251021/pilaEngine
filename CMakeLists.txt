cmake_minimum_required(VERSION 3.16)
project(PilaEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)

set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(glfw)

# ------------------------------------------
find_package(OpenGL REQUIRED)

# 1. Автоматически собираем все файлы исходного кода (.cpp и .c)
file(GLOB_RECURSE SOURCE_FILES 
    "src/*.cpp"
    "src/*.c"
)

# 2. Создаем исполняемый файл
add_executable(PilaEngine ${SOURCE_FILES})

# 3. АВТОПОДКЛЮЧЕНИЕ ИНКЛЮДОВ:
# Говорим CMake, что для PilaEngine папка "include" является корневой для заголовочных файлов.
# Теперь внутри проекта можно писать #include "Window.h" или #include "PilaEngine/Log.h"
target_include_directories(PilaEngine PRIVATE include)

# 4. Линкуем библиотеки
target_link_libraries(PilaEngine PRIVATE glfw OpenGL::GL)