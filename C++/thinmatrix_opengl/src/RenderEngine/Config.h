#ifndef CONFIG_H
#define CONFIG_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace renderEngine {

struct Config {
    const char* title = "thinmatrix_tutorial";
    int width = 1280;
    int height = 720;
    bool fullscreen = false;
    bool antialias = true;
    int samples = 4;
};

}
#endif // CONFIG_H
