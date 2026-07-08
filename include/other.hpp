#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

struct vector2
{
    float x;
    float y;
};

struct Time {
    float deltaTime = 0.0f;
    double lastTime = 0.0;
    
    void update() {
        double currentTime = glfwGetTime();
        deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;
    }
};

struct Vertex2D {
    glm::vec2 pos;
    glm::vec3 color;
};