#ifndef RAWMODEL_H
#define RAWMODEL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace renderEngine {

class RawModel {
public:
    RawModel(GLuint VAO, GLuint vertexCount);

    ~RawModel();

    GLuint getVAO() const;

    GLuint getVertexCount() const;

private:
    GLuint m_VAO;
    GLuint m_vertexCount;
};

}
#endif // RAWMODEL_H
