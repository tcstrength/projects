#ifndef WINDOW_H
#define WINDOW_H

#include "Config.h"
#include "../Events/InputEvent.h"
#include "../Utils/Log.h"

namespace graphics {

class Window
{
public:
    Window(Config& config);

    ~Window();

    void clear();

    void display();

    bool isOpen();

    void close();

    void getSize(int& width, int& height);

private:
    void setupWindow();

    void setupGL();

    Config& m_config;
    GLFWwindow* m_window;
};
}

#endif // WINDOW_H
