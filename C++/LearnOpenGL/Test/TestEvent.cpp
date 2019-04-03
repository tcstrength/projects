#include "TestEvent.h"

namespace test {


TestEvent::TestEvent()
:   m_window(m_config)
,   m_shader()
,   m_camera(glm::vec3(0.f, 0.f, -10.f))
{
    events::InputEvent::instance()->reg(events::EventType::MOUSE_MOTION, this);
    events::InputEvent::instance()->reg(events::EventType::KEY_PRESS, this);
    events::InputEvent::instance()->reg(events::EventType::KEY_RELEASE, this);
    events::InputEvent::instance()->reg(events::EventType::MOUSE_SCROLL, this);
    graphics::Transform::updateProjection(m_config.width, m_config.height);
}

void TestEvent::loop()
{
    graphics::Mesh cube(graphics::Mesh::cubeVertices(),
                        graphics::Mesh::cubeIndices());

    graphics::Mesh quad(graphics::Mesh::quadVertices(),
                        graphics::Mesh::quadIndices());

    graphics::Model nanosuit("models/nanosuit/nanosuit.obj");
    graphics::Model monkey("models/tumlum/jeep.obj");
    graphics::Model anim("models/Character Running/Character Running.dae");

    while (m_window.isOpen())
    {
        m_window.clear();
        m_shader.bind();
        m_camera.doMovement();

        m_shader.load(graphics::Transform::transform(m_camera.getView(),
                                         glm::vec3(5.f, 0.f, -1.f),
                                         glm::vec3(1.f, 1.f, 1.f),
                                         0.f),
                      glm::vec4(1.f));
        nanosuit.draw();

        m_shader.load(graphics::Transform::transform(m_camera.getView(),
                                         glm::vec3(25.f, 0.f, -1.f),
                                         glm::vec3(0.05f, 0.05f, 0.05f),
                                         0.f),
                      glm::vec4(1.f));
        monkey.draw();

        m_shader.load(graphics::Transform::transform(m_camera.getView(),
                                         glm::vec3(100.f, 0.f, -1.f),
                                         glm::vec3(1.f, 1.f, 1.f),
                                         0.f),
                      glm::vec4(1.f));
        anim.draw();

        m_window.display();
    }
}

void TestEvent::eventCallback(const events::EventType& type, const events::EventData& data)
{
    glm::vec<2, double> center(m_config.width / 2, m_config.height / 2);

    switch(type)
    {
        case events::EventType::KEY_PRESS:
            m_camera.processKey(data.key, data.keyAction);
            break;
        case events::EventType::KEY_RELEASE:
            m_camera.processKey(data.key, data.keyAction);
            break;
        case events::EventType::MOUSE_MOTION:
            m_camera.processMouse(center.x - data.mousePos.x, data.mousePos.y - center.y);
            break;
        case events::EventType::BUTTON_PRESS:
            break;
        case events::EventType::BUTTON_RELEASE:
            break;
        case events::EventType::MOUSE_SCROLL:
            m_camera.processScroll(data.scroll);
            break;
    }
}

}
