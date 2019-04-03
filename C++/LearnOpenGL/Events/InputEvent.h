#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include "../Utils/Log.h"
#include "EventSignal.h"
#include <map>
#include <vector>
#include <GLFW/glfw3.h>

/// \note init in Graphics/Window

namespace events {

class InputEvent
{
public:
    static void init(GLFWwindow* window);

    static InputEvent* instance();

           void reg(const EventType& type, EventSignal* signal);

           bool hasEntered();

           bool hasFocused();

protected:
    InputEvent();

           void sendAll(const EventType& type);

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);

    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

    static void windowFocusCallback(GLFWwindow* window, int focused);

    static void cursorEnterCallback(GLFWwindow* window, int entered);

    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    std::map<EventType, std::vector<EventSignal*>> m_signals;
    EventData m_eventData;
    bool m_hasFocused;
    bool m_hasEntered;
};

}
#endif // INPUTEVENT_H
