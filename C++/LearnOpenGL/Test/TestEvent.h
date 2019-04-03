#ifndef TESTEVENT_H
#define TESTEVENT_H

#include "../Graphics/Include.h"
#include "../Entities/Camera.h"
#include "../Events/InputEvent.h"

namespace test {

class TestEvent : public events::EventSignal
{
public:

    TestEvent();

    void loop();

    void eventCallback(const events::EventType& type, const events::EventData& data);

private:
    graphics::Config m_config;
    graphics::Window m_window;
    graphics::MVPShader m_shader;
    entities::Camera m_camera;

};

}
#endif // TESTEVENT_H
