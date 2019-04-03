#include "GameEngine.h"

GameEngine::GameEngine(const Config &config)
:   m_config(config)
,   m_context(config)
,   m_info(m_context, m_config)
{
    m_group.add(new Player(m_context));
}

void GameEngine::begin()
{
    m_info.update();
    m_context.window.clear();
    handleEvents();
}

void GameEngine::run()
{
    Button button(m_context);

    while(m_context.window.isOpen())
    {
        begin();

        m_group.tick();
        m_group.draw();

        button.handleEvents();
        button.draw();

        end();
    }
}

void GameEngine::end()
{
    if (m_config.showFPS)
        m_info.draw();
    m_context.window.display();
}

void GameEngine::handleEvents()
{
    while (m_context.window.pollEvent(m_context.event))
    {
        switch(m_context.event.type)
        {
            case sf::Event::Closed:
                m_context.window.close();
                break;

            case sf::Event::KeyPressed:
                if (m_context.event.key.code == sf::Keyboard::Escape)
                {
                    m_context.window.close();
                }
                break;

            default:
                break;
        }
    }
}
