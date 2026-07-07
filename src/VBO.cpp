#include "VBO.hpp"

VBO::VBO() {
    glGenBuffers(1, &this->id);
}
VBO::~VBO() {
    glDeleteBuffers(1, &this->id);
}
void VBO::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
}
void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
template <typename T>
void VBO::setData(const std::vector<T>& data, GLenum Usage = GL_STATIC_DRAW) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), data.data(), Usage);
}
template <typename T>
void VBO::setData(const T* data, int count, GLenum Usage = GL_STATIC_DRAW) {
    bind();
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(T), data, Usage);
}