#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

namespace entities {

class Camera
{
public:
    Camera(const glm::vec3& initPos);

    void processMouse(float offsetX, float offsetY);

    void processScroll(double yoffset);

    void processKey(int key, int action);

    void updateView();

    void doMovement();

    void setPosition(const glm::vec3& position);

    const glm::vec3& getPosition() const;

    const glm::mat4& getView();

private:
    glm::mat4 m_view;
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    float     m_pitch;
    float     m_yaw;
    float     m_sensitive;
    float     m_speed;
    bool      m_keys[1024];
};

}
#endif // CAMERA_H
