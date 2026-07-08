#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class EBO
{
private:
    int count;
public:
    GLuint id;
    EBO();
    ~EBO();
    void bind() const ;
    void unbind() const ;
    void setData(const std::vector<GLuint>& indices, GLenum Usage = GL_STATIC_DRAW);
    void setData(const GLuint* indices, int count, GLenum Usage = GL_STATIC_DRAW);
    GLuint getCount() const { return count; }
};