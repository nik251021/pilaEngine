#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class VBO
{
private:
    
public:
    GLuint id;
    VBO();
    ~VBO();
    void bind();
    void unbind();
    template <typename T>
    void setData(const std::vector<T>& data, GLenum Usage = GL_STATIC_DRAW);
    template <typename T>
    void setData(const T* data, int count, GLenum Usage = GL_STATIC_DRAW);
};