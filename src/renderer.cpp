#include <renderer.hpp>

void renderer::clear() const {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void renderer::drawTriangle(const triangle& shape, const shader& shader) const {
    shape.bind();
    shader.bind();

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}

void renderer::drawQuad(const quadMesh& shape, const shader& shader) const {
    shape.bind();
    shader.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}