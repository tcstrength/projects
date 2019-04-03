#include "Mesh.h"

namespace graphics {

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices)
:   m_VAO(0xFFFFFFFF)
,   m_VBO(0xFFFFFFFF)
,   m_IBO(0xFFFFFFFF)
,   m_numIndices(indices.size())
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_IBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * m_numIndices, &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_IBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Mesh::draw()
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_numIndices, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

const std::vector<Vertex>& Mesh::quadVertices()
{
    static glm::vec2 topLeft (0.f, 0.f);
    static glm::vec2 topRight(1.f, 0.f);
    static glm::vec2 botLeft (0.f, 1.f);
    static glm::vec2 botRight(1.f, 1.f);
    static std::vector<Vertex> vertices = {
        Vertex({glm::vec3(-1.0f,  1.0f, 0.f),   topLeft , glm::vec3(0.f, 0.f, 1.f)}),
        Vertex({glm::vec3( 1.0f,  1.0f, 0.f),   topRight, glm::vec3(0.f, 0.f, 1.f)}),
        Vertex({glm::vec3( 1.0f, -1.0f, 0.f),   botRight, glm::vec3(0.f, 0.f, 1.f)}),
        Vertex({glm::vec3(-1.0f, -1.0f, 0.f),   botLeft , glm::vec3(0.f, 0.f, 1.f)}),
    };

    return vertices;
}

const std::vector<GLuint>& Mesh::quadIndices()
{
    static std::vector<GLuint> indices =
    {
        0, 1, 2,
        2, 3, 0
    };

    return indices;
}

const std::vector<Vertex>& Mesh::cubeVertices()
{
    static glm::vec2 topLeft (0.f, 0.f);
    static glm::vec2 topRight(1.f, 0.f);
    static glm::vec2 botLeft (0.f, 1.f);
    static glm::vec2 botRight(1.f, 1.f);
    static std::vector<Vertex> vertices = {
        Vertex({glm::vec3(-1.0, -1.0,  1.0), topLeft , glm::vec3(0.f, 0.f, 1.f)}),
        Vertex({glm::vec3( 1.0, -1.0,  1.0), topRight, glm::vec3(0.f, 0.f, 1.f)}),
        Vertex({glm::vec3( 1.0,  1.0,  1.0), botLeft , glm::vec3(0.f, 0.f, 1.f)}),
        Vertex({glm::vec3(-1.0,  1.0,  1.0), botRight, glm::vec3(0.f, 0.f, 1.f)}),

        Vertex({glm::vec3(-1.0, -1.0, -1.0), topLeft , glm::vec3(0.f, 0.f, -1.f)}),
        Vertex({glm::vec3( 1.0, -1.0, -1.0), topRight, glm::vec3(0.f, 0.f, -1.f)}),
        Vertex({glm::vec3( 1.0,  1.0, -1.0), botLeft , glm::vec3(0.f, 0.f, -1.f)}),
        Vertex({glm::vec3(-1.0,  1.0, -1.0), botRight, glm::vec3(0.f, 0.f, -1.f)}),
    };

    return vertices;
}

const std::vector<GLuint>& Mesh::cubeIndices()
{
    static std::vector<GLuint> indices = {
        // front
        0, 1, 2,
        2, 3, 0,
        // right
        1, 5, 6,
        6, 2, 1,
        // back
        7, 6, 5,
        5, 4, 7,
        // left
        4, 0, 3,
        3, 7, 4,
        // bottom
        4, 5, 1,
        1, 0, 4,
        // top
        3, 2, 6,
        6, 7, 3
    };

    return indices;
}

}
