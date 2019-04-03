#ifndef DISPLAY_H
#define DISPLAY_H

#include "../Utils/Log.h"
#include "Config.h"

namespace renderEngine {

class Display {
public:
    static GLFWwindow* window;

    static void create(const Config& config);

    static void update();

    static void close();

    static bool isOpen();

private:
    static void setupGLFW(const Config& config);

    static void setupGL();

};

}
#endif // DISPLAY_H
