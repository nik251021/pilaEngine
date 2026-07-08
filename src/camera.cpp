#include "camera.hpp"

Camera2D::Camera2D(float windowWidth, float windowHeight)
    : position(0.0f, 0.0f), zoom(1.0f), width(windowWidth), height(windowHeight) 
{
    updateMatrices();
}

void Camera2D::updateMatrices() {
    float halfW = (width / 2.0f) * zoom;
    float halfH = (height / 2.0f) * zoom;
    
    projectionMatrix = glm::ortho(-halfW, halfW, -halfH, halfH, -1.0f, 1.0f);

    viewMatrix = glm::mat4(1.0f);
    viewMatrix = glm::translate(viewMatrix, glm::vec3(-position, 0.0f));
}

void Camera2D::move(const glm::vec2& offset) {
    position += offset;
    updateMatrices();
}

void Camera2D::setPosition(const glm::vec2& pos) {
    position = pos;
    updateMatrices();
}

void Camera2D::setZoom(float value) {
    zoom = value;
    if (zoom < 0.01f) zoom = 0.01f;
    updateMatrices();
}

void Camera2D::updateWindowSize(float windowWidth, float windowHeight) {
    width = windowWidth;
    height = windowHeight;
    updateMatrices();
}

glm::mat4 Camera2D::getViewProjection() const {
    return projectionMatrix * viewMatrix;
}