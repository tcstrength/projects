#include "MVPShader.h"

namespace graphics {

const char* MVP_VERTEX = "mvp.vs";
const char* MVP_FRAGMENT = "mvp.fs";

MVPShader::MVPShader()
:   Shader(MVP_VERTEX, MVP_FRAGMENT)
{
    m_MVPUniform = getUniform("MVP");
    m_objColorUniform = getUniform("objColor");
}

void MVPShader::load(const glm::mat4 &MVP, const glm::vec4 &objColor)
{
    glUniformMatrix4fv(m_MVPUniform, 1, GL_FALSE, &MVP[0][0]);
    glUniform4fv(m_objColorUniform, 1, &objColor[0]);
}

}
