#include "Window.h"

namespace graphics {

Window::Window(Config& config)
:   m_config(config)
,   m_window(nullptr)
{
    setupWindow();
    setupGL();
    events::InputEvent::init(m_window);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwPollEvents();

    if (m_config.lockCursor &&
        events::InputEvent::instance()->hasEntered() &&
        events::InputEvent::instance()->hasFocused())
    {
        glfwSetCursorPos(m_window, m_config.width / 2, m_config.height / 2);
    }
}

void Window::display()
{
    glfwSwapBuffers(m_window);
}

bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_window);
}

void Window::close()
{
    glfwSetWindowShouldClose(m_window, GLFW_TRUE);
}

void Window::getSize(int& width, int& height)
{
    glfwGetWindowSize(m_window, &width, &height);
}

void Window::setupWindow()
{
    if (!glfwInit()) {
        LOG_ERROR("Could not initialize GLFW!");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, m_config.antialias);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    if (m_config.fullscreen) {
        const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        m_config.width = vidmode->width;
        m_config.height = vidmode->height;
    }

    m_window = glfwCreateWindow(m_config.width, m_config.height, m_config.title.c_str(), nullptr, nullptr);

    if (m_window == nullptr) {
        LOG_ERROR("Could not create new Window!");
    }

    if (m_config.vsync == false) {
        glfwSwapInterval(0);
    }

    glfwMakeContextCurrent(m_window);
}

void Window::setupGL()
{
    if (glewInit() != GLEW_OK) {
        LOG_ERROR("Could not initialize GLEW!");
    }

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

}
