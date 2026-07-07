#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VBO.hpp"
#include "EBO.hpp"

struct VertexAttribute {
    GLuint index;         // location в шейдере (например, layout(location = 0))
    GLint size;           // Количество компонент (3 для x, y, z)
    GLenum type;          // Тип данных (GL_FLOAT)
    GLboolean normalized; // Нужно ли нормализовать (GL_FALSE)
    GLsizei stride;       // Шаг до следующей вершины (размер всей структуры вершины в байтах)
    const void* pointer;  // Смещение от начала структуры (offset)
};

class VAO
{
private:
    
public:
    GLuint id;

    VAO();
    ~VAO();

    void bind();
    void unbind();

    void addBuffer(VBO &vbo, const std::vector<VertexAttribute>& attributes);
    void setIndexBuffer(EBO& ebo);
};
