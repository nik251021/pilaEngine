#include "EBO.hpp"

EBO::EBO() {
    glGenBuffers(1, &this->id);
}
EBO::~EBO() {
    glDeleteBuffers(1, &this->id);
}
void EBO::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}
void EBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void EBO::setData(const std::vector<GLuint>& indices, GLenum Usage = GL_STATIC_DRAW) {
    this->count = indices.size();
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), Usage);
}
void EBO::setData(const GLuint* indices, int count, GLenum Usage = GL_STATIC_DRAW) {
    this->count = count;
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, Usage);
}