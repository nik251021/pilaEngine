#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <filesystem>
#include <thread>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "window.hpp"
#include "other.hpp"
#include "shader.hpp"
#include "shapes.hpp"
#include "gameShapes.hpp"
#include "renderer.hpp"

namespace fs = std::filesystem;

const double timePerFrame = 1.0/60.0;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        fs::path pathToScene = argv[1];
        std::cout << "Path to scene: " << pathToScene.string() << std::endl;
    }

    if (!glfwInit()) {
        std::cerr << "Glfw cant initialize" << std::endl;
        return 1;
    }

    window window(800, 600, "Hello biden");

    shader myShader(fs::path("shaders/vertex.glsl"), fs::path("shaders/fragment.glsl"));

    renderer myRenderer;

    triangle myTriangle(
        glm::vec2(0.0f, 0.0f),
        glm::vec2(0.0f, 0.5f),
        glm::vec2(-0.5f, -0.5f),
        glm::vec2(0.5f, -0.5f),
        glm::vec3(0.0f, 1.0f, 0.0f) 
    );

    Time gameTime;
    gameTime.lastTime = glfwGetTime();

    //Test
    gTriangle player(myTriangle, glm::vec2(0.0f, 0.0f));
    float playerSpeed = 1.5f;
    //
    while (!window.shouldClose())
    {
        gameTime.update();
        double start = glfwGetTime();
        
        window.pollEvents();

        myRenderer.clear();
        //test
        glm::vec2 moveOffset(0.0f);

        if (window.isKeyPressed(GLFW_KEY_W) == true) moveOffset.y += playerSpeed * gameTime.deltaTime;
        if (window.isKeyPressed(GLFW_KEY_S) == true) moveOffset.y -= playerSpeed * gameTime.deltaTime;
        if (window.isKeyPressed(GLFW_KEY_A) == true) moveOffset.x -= playerSpeed * gameTime.deltaTime;
        if (window.isKeyPressed(GLFW_KEY_D) == true) moveOffset.x += playerSpeed * gameTime.deltaTime;

        player.move(moveOffset);
        player.rotate(45 * gameTime.deltaTime);
        player.draw(myRenderer, myShader);
        //
        window.swapBuffers();

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