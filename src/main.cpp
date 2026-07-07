#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <filesystem>

#include "window.hpp"
#include "other.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    fs::path pathToScene = argv[1];
    std::cout << "Path to scene: " << pathToScene.string() << std::endl;

    if (!glfwInit()) {
        std::cerr << "Glfw cant initialize" << std::endl;
        return 1;
        glfwTerminate();
    }

    window window(800,600, "Hello biden");

    Time gameTime;
    gameTime.lastTime = glfwGetTime();

    while (!window.shouldClose())
    {
        gameTime.update();
        std::cout << gameTime.deltaTime << std::endl;
        if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
            std::cout << "Escape, stopping" << std::endl;
            break;
        }
        std::cout << "Mouse X: [ " << window.getMousePos().x << " ] | Mouse Y: [ " << window.getMousePos().y << " ]" << std::endl;
        window.pollEvents();
    }
    glfwTerminate();
    std::cout << "Window was closed" << std::endl;

    return 0;
}