#include <window.hpp>

bool window::createWindow(int sizeX, int sizeY, std::string name) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    this->Window = glfwCreateWindow(sizeX, sizeY, name.c_str(), nullptr, nullptr);
    if (this->Window == nullptr) {
        std::cerr << "Window is null" << std::endl;
        critError = true;
        return false;
    }

    glfwMakeContextCurrent(this->Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD Init Failed" << std::endl;
        critError = true;
        return false;
    }
    glfwSwapInterval(1);

    std::cout << "OpenGL Context Created: " << glGetString(GL_VERSION) << std::endl;
    return true;
}
bool window::shouldClose() {
    if (critError) {
        return true;
    }
    return glfwWindowShouldClose(this->Window);
}

bool window::isKeyPressed(int keyCode) {
    int state = glfwGetKey(this->Window, keyCode);
    return state == GLFW_PRESS | state == GLFW_REPEAT;
};
bool window::isMouseButtonPressed(int buttonCode) {
    int state = glfwGetMouseButton(this->Window, buttonCode);
    return state == GLFW_PRESS | state == GLFW_REPEAT;
}
vector2 window::getMousePos() {
    double posx, posy;
    glfwGetCursorPos(this->Window, &posx, &posy);

    return vector2{static_cast<float>(posx), static_cast<float>(posy)};
}


void window::pollEvents() {
    glfwPollEvents();
}