#include <VAO.hpp>

VAO::VAO() {
    glGenVertexArrays(1, &this->id);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &this->id);
}

void VAO::bind() const {
    glBindVertexArray(this->id);
}

void VAO::unbind() const {
    glBindVertexArray(0);
}

void VAO::addBuffer(VBO &vbo, const std::vector<VertexAttribute>& attributes) {
    bind();
    vbo.bind();
    for (const auto& attr : attributes) {
        glEnableVertexAttribArray(attr.index);

        glVertexAttribPointer(
            attr.index,
            attr.size,
            attr.type,
            attr.normalized,
            attr.stride,
            attr.pointer
        );
    }
}

void VAO::setIndexBuffer(EBO& ebo) {
    bind();
    ebo.bind();
}