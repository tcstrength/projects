#include "Display.h"

namespace renderEngine {

GLFWwindow* Display::window = nullptr;

void Display::create(const Config& config)
{
    setupGLFW(config);
    setupGL();
}

void Display::update()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Display::close()
{
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

bool Display::isOpen()
{
    return !glfwWindowShouldClose(window);
}

void Display::setupGLFW(const Config& config)
{
    if (!glfwInit()) {
        LOG_ERROR("Could not initialize GLFW!");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    if (config.antialias) {
        glfwWindowHint(GLFW_SAMPLES, config.samples);
    }

    if (config.fullscreen) {
        const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        window = glfwCreateWindow(vidmode->width, vidmode->height, config.title, glfwGetPrimaryMonitor(), nullptr);
    }
    else {
        window = glfwCreateWindow(config.width, config.height, config.title, nullptr, nullptr);
    }


    if (window == nullptr) {
        LOG_ERROR("Could not create new Window!");
    }

    glfwMakeContextCurrent(window);
}

void Display::setupGL()
{
    if (glewInit() != GLEW_OK) {
        LOG_DEBUG("Failed to initialize GLEW");
    }

    glClearColor(0.2f, 0.2f, 0.2f, 1.f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_MULTISAMPLE);
    glCullFace(GL_BACK);
}

}
