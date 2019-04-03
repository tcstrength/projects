#include "GameEngine.h"

GameEngine::GameEngine(Context& context, const Config& config)
:   m_config(config)
,   m_context(context)
,   m_handler(context)
{
    LOG_DEBUG("Game Engine starting...");


    m_handler.createRifleMan({500, 500});
    m_handler.createBasicEnemy({100, 100});
    m_handler.createBasicEnemy({200, 200});
    m_handler.createBasicEnemy({400, 400});
    m_handler.createBasicEnemy({200, 500});
}

void GameEngine::tick()
{
    FadeOut::get().tick();
    FadeIn::get().tick();
    m_handler.tick();
}

void GameEngine::draw()
{
    m_handler.draw();
}

void GameEngine::handleEvents()
{
    auto pos = m_handler.getRifleman(0)->getPosition();
    uint index = 0;
    switch(m_context.event.type)
    {
        case sf::Event::MouseButtonPressed:
            index = m_handler.createBullet(pos);
            m_handler.getObject(index)->playAnim(m_handler.getRifleman(0)->getAnim());
            break;

        default:
            break;
    }
}
