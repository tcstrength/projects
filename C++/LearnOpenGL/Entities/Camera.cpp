#include "Camera.h"
namespace entities {

Camera::Camera(const glm::vec3& initPos)
:   m_position(initPos)
,   m_front(0.f, 0.f, -1.f)
,   m_up(0.f, 1.f, 0.f)
,   m_pitch(0.f)
,   m_yaw(-90.f)
,   m_sensitive(0.05f)
,   m_speed(1.f)
{
    updateView();

    for (uint i = 0; i < 1024; ++i)
    {
        m_keys[i] = false;
    }
}

void Camera::processMouse(float offsetX, float offsetY)
{
    m_pitch += offsetY * m_sensitive;
    m_yaw += offsetX * m_sensitive;

    updateView();
}

void Camera::processScroll(double yoffset)
{
    if (yoffset < 0)
    {
        m_position -= m_front * 3.f;
    }
    else
    {
        m_position += m_front * 3.f;
    }

    updateView();
}

void Camera::processKey(int key, int action)
{
    m_keys[key] = (GLFW_PRESS == action);
}

void Camera::doMovement()
{
    if (m_keys[GLFW_KEY_W])
    {
        m_position += m_front * m_speed;
        updateView();
    }

    if (m_keys[GLFW_KEY_S])
    {
        m_position -= m_front * m_speed;
        updateView();
    }

    if (m_keys[GLFW_KEY_D])
    {
        m_position -= glm::normalize(glm::cross(m_front, m_up)) * m_speed;
        updateView();
    }

    if (m_keys[GLFW_KEY_A])
    {
        m_position += glm::normalize(glm::cross(m_front, m_up)) * m_speed;
        updateView();
    }

    if (m_keys[GLFW_KEY_SPACE])
    {
        m_position -= m_up;
        updateView();
    }
}

const glm::mat4&Camera::getView()
{
    return m_view;
}

void Camera::updateView()
{
    if (m_pitch > 89.f)
    {
        m_pitch = 89.f;
    }

    if (m_pitch < -89.f)
    {
        m_pitch = -89.f;
    }

    float radPitch = glm::radians(m_pitch);
    float radYaw = glm::radians(m_yaw);

    m_front.x = std::cos(radPitch) * std::cos(radYaw);
    m_front.y = std::sin(radPitch);
    m_front.z = std::cos(radPitch) * std::sin(radYaw);
    m_front = glm::normalize(m_front);

    m_view = glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::setPosition(const glm::vec3& position)
{
    m_position = position;
    updateView();
}

const glm::vec3&Camera::getPosition() const
{
    return m_position;
}

}
