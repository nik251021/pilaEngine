#pragma once

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