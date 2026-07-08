#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VBO.hpp"
#include "EBO.hpp"

struct VertexAttribute {
    GLuint index;
    GLint size;
    GLenum type;
    GLboolean normalized;
    GLsizei stride;
    const void* pointer;
};

class VAO
{
private:
    
public:
    GLuint id;

    VAO();
    ~VAO();

    void bind() const ;
    void unbind() const ;

    void addBuffer(VBO &vbo, const std::vector<VertexAttribute>& attributes);
    void setIndexBuffer(EBO& ebo);
};
