#include "InputEvent.h"

namespace events {

InputEvent::InputEvent()
:   m_hasEntered(0)
,   m_hasFocused(0)
{

}

void InputEvent::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    instance()->m_eventData.key = key;
    instance()->m_eventData.keyAction = action;

    switch (action)
    {
        case GLFW_PRESS:
            instance()->sendAll(EventType::KEY_PRESS);
            break;

        case GLFW_RELEASE:
            instance()->sendAll(EventType::KEY_RELEASE);
            break;
    }
}

void InputEvent::mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
    instance()->m_eventData.button = button;
    instance()->m_eventData.buttonAction = action;

    switch (action)
    {
        case GLFW_PRESS:
            instance()->sendAll(EventType::BUTTON_PRESS);
            break;

        case GLFW_RELEASE:
            instance()->sendAll(EventType::BUTTON_RELEASE);
            break;
    }
}

void InputEvent::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    instance()->m_eventData.mousePos = glm::vec<2, double>(xpos, ypos);

    instance()->sendAll(EventType::MOUSE_MOTION);
}

void InputEvent::windowFocusCallback(GLFWwindow* window, int focused)
{
    instance()->m_hasFocused = focused;
}

void InputEvent::cursorEnterCallback(GLFWwindow* window, int entered)
{
    instance()->m_hasEntered = entered;
}

void InputEvent::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    instance()->m_eventData.scroll = yoffset;
    instance()->sendAll(EventType::MOUSE_SCROLL);
}

void InputEvent::init(GLFWwindow* window)
{
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetWindowFocusCallback(window, windowFocusCallback);
    glfwSetCursorEnterCallback(window, cursorEnterCallback);
    glfwSetScrollCallback(window, scrollCallback);
}

InputEvent* InputEvent::instance()
{
    static InputEvent e;
    return &e;
}

void InputEvent::sendAll(const EventType& type)
{
    if (m_hasEntered == false || m_hasFocused == false)
    {
        return;
    }

    auto signals = m_signals[type];

    for (auto sig : signals)
    {
        sig->eventCallback(type, m_eventData);
    }
}

void InputEvent::reg(const EventType& type,EventSignal* signal)
{
    m_signals[type].push_back(signal);
}

bool InputEvent::hasEntered()
{
    return m_hasEntered;
}

bool InputEvent::hasFocused()
{
    return m_hasFocused;
}

}
