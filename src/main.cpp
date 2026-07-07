#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <filesystem>
#include <thread>

#include "window.hpp"
#include "other.hpp"
#include "shader.hpp"

namespace fs = std::filesystem;

const double timePerFrame = 1.0/60.0;

int main(int argc, char* argv[]) {
    fs::path pathToScene = argv[1];
    std::cout << "Path to scene: " << pathToScene.string() << std::endl;

    if (!glfwInit()) {
        std::cerr << "Glfw cant initialize" << std::endl;
        return 1;
        glfwTerminate();
    }

    window window(800,600, "Hello biden");

    shader myShader(fs::path("shaders/vertex.glsl"), fs::path("shaders/fragment.glsl"));
    std::filesystem::path vertPath = "shaders/vertex.glsl";
    std::filesystem::path fragPath = "shaders/fragment.glsl";

    Time gameTime;
    gameTime.lastTime = glfwGetTime();

    while (!window.shouldClose())
    {
        gameTime.update();
        double start = glfwGetTime();

        if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
            std::cout << "Escape, stopping" << std::endl;
            break;
        }
        
        window.pollEvents();
        double duration = glfwGetTime() - start;
        if (duration < timePerFrame) {
            double sleepDuration = timePerFrame - duration;
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepDuration));
        }
    }
    glfwTerminate();
    std::cout << "Window was closed" << std::endl;

    return 0;
}