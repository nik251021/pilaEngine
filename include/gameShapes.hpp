#pragma once
#include "renderer.hpp"
#include "shapes.hpp"

class gTriangle
{
private:
    triangle mesh;
    glm::vec2 position;
    float rotation;
public:
    gTriangle(const triangle& mesh, glm::vec2 pos);

    void move(glm::vec2 offset);
    void setPos(glm::vec2 pos);
    void rotate(float degree);
    void setRotaion(float degree);

    void draw(renderer& r, const shader& s, const glm::mat4& viewProj) const;

    glm::vec2 getPos() const { return position; }
    float getRotation() const { return rotation; }
};

class gQuad
{
private:
    quadMesh mesh;
    glm::vec2 position;
    float rotation;
public:
    gQuad(const quadMesh& mesh, glm::vec2 pos);

    void move(glm::vec2 offset);
    void setPos(glm::vec2 pos);
    void rotate(float degree);
    void setRotaion(float degree);

    void draw(renderer& r, const shader& s, const glm::mat4& viewProj) const;

    glm::vec2 getPos() const { return position; }
    float getRotation() const { return rotation; }
};