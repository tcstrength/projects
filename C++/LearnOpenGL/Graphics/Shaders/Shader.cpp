#include "Shader.h"

namespace graphics {

std::string SHADERS_DIR = "shaders/";

Shader::Shader(const char * vs, const char * fs)
{
    GLuint vertexShader = compileShader(vs, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fs, GL_FRAGMENT_SHADER);

    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, vertexShader);
    glAttachShader(m_shaderProgram, fragmentShader);
    glLinkProgram(m_shaderProgram);

    int success = 0;
    char infoLog[512];

    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(m_shaderProgram, 512, nullptr, infoLog);
        LOG_ERROR("Link Program: " << infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
//    LOG_DEBUG("Ahihi");
    glDeleteProgram(m_shaderProgram);
}

void Shader::bind()
{
    glUseProgram(m_shaderProgram);
}

GLuint Shader::getUniform(const char * uniformName)
{
    return glGetUniformLocation(m_shaderProgram, uniformName);
}

GLuint Shader::compileShader(const char * path, GLuint type)
{
    GLuint shader = glCreateShader(type);
    std::string code;
    std::ifstream shfile(SHADERS_DIR + path);
    std::stringstream shstream(code);

    if (shfile.is_open() == false)
    {
        LOG_ERROR("File not found: " << path);
    }

    shstream << shfile.rdbuf();
    code = shstream.str();
    shfile.close();

    const GLchar* shaderCode = code.c_str();

    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    int success = 0;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        LOG_ERROR("Compile Shader: " << std::string(infoLog));
    }

    return shader;
}

}
