#include "shapes.hpp"

triangle::triangle(const glm::vec2& center, const glm::vec2& v1, const glm::vec2& v2, const glm::vec2& v3, const glm::vec3& color) {
    Vertex2D vertices[] {
        {center + v1, color},
        {center + v2, color},
        {center + v3, color}
    };

    unsigned int indices[] {
        0,1,2
    };
    VBO.setData(vertices, 3, GL_STATIC_DRAW);
    EBO.setData(indices, 3, GL_STATIC_DRAW);
    std::vector<VertexAttribute> attributes{
        {
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex2D),
            (void*)offsetof(Vertex2D, pos)
        },
        {
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex2D),
            (void*)offsetof(Vertex2D, color)
        }
    };
    VAO.addBuffer(VBO, attributes);
    VAO.setIndexBuffer(EBO);
};

void triangle::bind() const {
    VAO.bind();
    EBO.bind();
}

quadMesh::quadMesh(const glm::vec2& center, const glm::vec2& v1, const glm::vec2& v2, const glm::vec2& v3, const glm::vec2& v4, const glm::vec3& color)
{
    Vertex2D vertices[] {
        {center + v1, color},
        {center + v2, color},
        {center + v3, color},
        {center + v4, color}
    };
    unsigned int indices[] {
        0,1,2,
        2,3,0
    };
    VBO.setData(vertices, 4, GL_STATIC_DRAW);
    EBO.setData(indices, 6, GL_STATIC_DRAW);
        std::vector<VertexAttribute> attributes{
        {
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex2D),
            (void*)offsetof(Vertex2D, pos)
        },
        {
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex2D),
            (void*)offsetof(Vertex2D, color)
        }
    };
    VAO.addBuffer(VBO, attributes);
    VAO.setIndexBuffer(EBO);
}

void quadMesh::bind() const {
    VAO.bind();
    EBO.bind();
}