#include "ModelLoader.h"

namespace renderEngine {

ModelLoader::ModelLoader()
{

}

ModelLoader::~ModelLoader()
{
    for (uint i = 0; i < m_VBOs.size(); ++i)
    {
        glDeleteBuffers(1, &m_VBOs[i]);
    }

    for (uint i = 0; i < m_VAOs.size(); ++i)
    {
        glDeleteVertexArrays(1, &m_VAOs[i]);
    }
}

RawModel ModelLoader::loadRawModel()
{
    
}

ModelLoader* ModelLoader::instance()
{
    static ModelLoader modLoader;
    return &modLoader;
}

}