#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace graphics {
struct Config
{
    std::string title;
    int width = 1280;
    int height = width * 9.f / 16.f;
    int antialias = 8;
    bool fullscreen = false;
    bool vsync = true;
    bool lockCursor = true;
};
}

#endif // CONFIG_H
