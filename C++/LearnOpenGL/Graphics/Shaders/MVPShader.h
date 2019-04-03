#ifndef MVPSHADER_H
#define MVPSHADER_H

#include "Shader.h"

namespace graphics {

class MVPShader : public Shader
{
public:
    MVPShader();

    void load(const glm::mat4& MVP, const glm::vec4& objColor);
private:
    GLuint m_MVPUniform;
    GLuint m_objColorUniform;
};

}
#endif // MVPSHADER_H
