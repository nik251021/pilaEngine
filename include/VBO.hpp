#pragma once
#include <glad/glad.h>
#include <vector>

class VBO {
private:
    GLuint id;
public:
    VBO();
    ~VBO();
    void bind() const;
    void unbind() const;

    template <typename T>
    void setData(const std::vector<T>& data, GLenum Usage) {
        bind();
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), Usage);
    }

    template <typename T>
    void setData(const T* data, int count, GLenum Usage) {
        bind();
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(T), data, Usage);
    }
};