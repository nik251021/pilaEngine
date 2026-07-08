#include <gameShapes.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

gTriangle::gTriangle(const triangle& mesh, glm::vec2 pos)
    : mesh(mesh), position(pos), rotation(0.0f) {}

void gTriangle::move(glm::vec2 offset) {
    position += offset;
}

void gTriangle::setPos(glm::vec2 pos) {
    position = pos;
}

void gTriangle::rotate(float degree) {
    rotation += glm::radians(degree);
}
void gTriangle::setRotaion(float degree) {
    rotation = glm::radians(degree);
}

void gTriangle::draw(renderer& r, const shader& s) const {
    s.bind();

    glm::mat4 transform = glm::mat4(1.0f);
    
    transform = glm::translate(transform, glm::vec3(position, 0.0f));
    transform = glm::rotate(transform, rotation, glm::vec3(0.0f, 0.0f, 1.0f));

    s.setMat4("transform", transform);

    r.drawTriangle(mesh, s);
}