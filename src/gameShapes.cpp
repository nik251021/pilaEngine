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

void gTriangle::draw(renderer& r, const shader& s, const glm::mat4& viewProj) const {
    s.bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 finalMatrix = viewProj * model;

    s.setMat4("transform", finalMatrix);

    r.drawTriangle(mesh, s);
}

gQuad::gQuad(const quadMesh& mesh, glm::vec2 pos)
    : mesh(mesh), position(pos), rotation(0.0f) {}

void gQuad::move(glm::vec2 offset) {
    position += offset;
}

void gQuad::setPos(glm::vec2 pos) {
    position = pos;
}

void gQuad::rotate(float degree) {
    rotation += glm::radians(degree);
}
void gQuad::setRotaion(float degree) {
    rotation = glm::radians(degree);
}

void gQuad::draw(renderer& r, const shader& s, const glm::mat4& viewProj) const {
    s.bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 finalMatrix = viewProj * model;

    s.setMat4("transform", finalMatrix);

    r.drawQuad(mesh, s);
}