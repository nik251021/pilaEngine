#include "VBO.hpp"

VBO::VBO() {
    glGenBuffers(1, &this->id);
}
VBO::~VBO() {
    glDeleteBuffers(1, &this->id);
}
void VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
}
void VBO::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}