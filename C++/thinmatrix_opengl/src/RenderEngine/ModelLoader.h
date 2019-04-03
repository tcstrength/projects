#pragma once

#include <vector>
#include <iostream>
#include "RawModel.h"


namespace renderEngine {

class ModelLoader {
public:
    static 
    ModelLoader* instance();

    RawModel loadRawModel();

private:
    ModelLoader();

    ~ModelLoader();

private:
    std::vector<GLuint> m_VAOs;
    std::vector<GLuint> m_VBOs;
};

}