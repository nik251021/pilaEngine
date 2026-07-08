#pragma once

#include <glm/glm.hpp>

#include "other.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

class triangle
{
private:
    VAO VAO;
    VBO VBO;
    EBO EBO;
public:
    triangle(const glm::vec2& center, const glm::vec2& v1, const glm::vec2& v2, const glm::vec2& v3, const glm::vec3& color);
    ~triangle() {
        
    };
    void bind() const;
    void unbind() const;
};