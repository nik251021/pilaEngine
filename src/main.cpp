#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <filesystem>
#include <thread>

#include "window.hpp"
#include "other.hpp"

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

    Time gameTime;
    gameTime.lastTime = glfwGetTime();

    while (!window.shouldClose())
    {
        gameTime.update();
        double start = glfwGetTime();
        std::cout << gameTime.deltaTime << std::endl;
        if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
            std::cout << "Escape, stopping" << std::endl;
            break;
        }
        std::cout << "Mouse X: [ " << window.getMousePos().x << " ] | Mouse Y: [ " << window.getMousePos().y << " ]" << std::endl;
        window.pollEvents();
        double duration = glfwGetTime() - start;
        if (duration < timePerFrame) {
            double sleepDuration = timePerFrame - duration;
            std::cout << "Sleep" << std::endl;
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepDuration));
        }
    }
    glfwTerminate();
    std::cout << "Window was closed" << std::endl;

    return 0;
}