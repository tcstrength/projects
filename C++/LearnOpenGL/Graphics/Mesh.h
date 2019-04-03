#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>
#include "Vertex.h"
#include "../Utils/Log.h"

namespace graphics {

class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

    ~Mesh();

    void draw();

    static
    const std::vector<Vertex>& quadVertices();

    static
    const std::vector<GLuint>& quadIndices();

    static
    const std::vector<Vertex>& cubeVertices();

    static
    const std::vector<GLuint>& cubeIndices();

private:
    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_IBO;
    GLuint m_numIndices;
};

}
#endif // MESH_H
