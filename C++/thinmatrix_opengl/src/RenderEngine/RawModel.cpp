#include "RawModel.h"

namespace renderEngine {

RawModel::RawModel(GLuint VAO, GLuint vertexCount)
:   m_VAO(VAO)
,   m_vertexCount(vertexCount)
{

}

RawModel::~RawModel()
{
}

GLuint RawModel::getVAO() const
{
    return m_VAO;
}

GLuint RawModel::getVertexCount() const
{
    return m_vertexCount;
}

}
