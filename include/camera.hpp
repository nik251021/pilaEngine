#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera2D {
private:
    glm::vec2 position;
    float zoom;
    
    float width;
    float height;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;

    void updateMatrices();

public:
    Camera2D(float windowWidth, float windowHeight);

    void move(const glm::vec2& offset);
    void setPosition(const glm::vec2& pos);
    void setZoom(float value);
    
    void updateWindowSize(float windowWidth, float windowHeight);

    glm::mat4 getViewProjection() const;
    glm::vec2 getPosition() const { return position; }
    float getZoom() const { return zoom; }
};