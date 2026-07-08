#pragma once

#include <glad/glad.h>
#include "shapes.hpp"
#include "shader.hpp"

class renderer {
private:

public:
    void clear() const;
    void drawTriangle(const triangle& shape, const shader& shader) const;
};