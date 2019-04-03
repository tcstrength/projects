#include "Info.h"

Info::Info(Context& context, const Config& config)
:   m_config(config)
,   m_context(context)
{
    m_fpsText.setFont(context.font);
    m_fpsText.setPosition(sf::Vector2f(m_config.width - 100, 10.f));
    m_fpsText.setCharacterSize(22);
    m_fpsText.setFillColor(sf::Color::Yellow);
}

void Info::update()
{
    uint fps = 1000000 / m_clock.getElapsedTime().asMicroseconds();
    std::string info = "FPS: " + std::to_string(fps);

    m_fpsText.setString(info);

    m_clock.restart();
}

void Info::draw()
{
    m_context.window.draw(m_fpsText);
}
