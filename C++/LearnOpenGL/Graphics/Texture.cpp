#include "Texture.h"

namespace graphics {

Texture::Texture(const char * path, bool linear)
:   m_path(path)
{
    LOG_DEBUG("Load " << path);
    int width;
    int height;
    u_char* image = SOIL_load_image(path, &width, &height, nullptr, SOIL_LOAD_RGBA);

    if (image == nullptr)
    {
        LOG_ERROR("Failed to load " << image);
    }

    glGenTextures(1, &m_TO);
    glBindTexture(GL_TEXTURE_2D, m_TO);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    if (linear)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);

    m_size = glm::vec2(width, height);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_TO);
    LOG_DEBUG("Texture " << this << " has been deleted");
}

void Texture::bind(GLuint texture)
{
    glActiveTexture(texture);
    glBindTexture(GL_TEXTURE_2D, m_TO);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

glm::vec2 Texture::getSize() const
{
    return m_size;
}

const std::string&Texture::getPath()
{
    return m_path;
}

}
