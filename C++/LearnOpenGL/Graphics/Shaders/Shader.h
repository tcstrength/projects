#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include <glm/glm.hpp>
#include "../../Utils/Log.h"

namespace graphics {

class Shader
{
public:
    Shader(const char* vs, const char* fs);

    ~Shader();

    GLuint getUniform(const char* uniformName);

    void bind();

private:
    GLuint compileShader(const char* sf, GLuint type);

    GLuint m_shaderProgram;
};

}
#endif // SHADER_H
