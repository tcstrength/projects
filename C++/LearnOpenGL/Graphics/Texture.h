#ifndef TEXTURE_H
#define TEXTURE_H

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "../Utils/Log.h"

namespace graphics {

class Texture
{
public:
    //////////////////////////////////////////////
    /// \brief Texture
    /// \param path real path is "textures/<path>"
    /// \param linear
    ///
    Texture(const char* path, bool linear = false);

    ~Texture();

    void bind(GLuint texture = GL_TEXTURE0);

    void unbind();

    glm::vec2 getSize() const;

    const std::string& getPath();

private:
    GLuint m_TO;
    std::string m_path;
    glm::vec2 m_size;
};

}

#endif // TEXTURE_H
