#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

#include "other.hpp"

class window
{
private:
    GLFWwindow* Window;
    bool critError;
public:
    window(int sizeX, int sizeY, std::string name) {
        bool result = createWindow(sizeX, sizeY, name);
        if (result == false) {
            std::cerr << "Error in creating window." << std::endl;
            glfwTerminate();
        }
    }
    bool createWindow(int sizeX, int sizeY, std::string name);
    bool shouldClose();

    bool isKeyPressed(int keyCode);
    bool isMouseButtonPressed(int buttonCode);
    vector2 getMousePos();

    void pollEvents();

    ~window();
};

inline window::~window(){
    if (this->Window) {
        glfwDestroyWindow(this->Window);
    }
    glfwTerminate();
}