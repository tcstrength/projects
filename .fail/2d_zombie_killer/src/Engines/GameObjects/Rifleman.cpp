#include "Rifleman.h"

Rifleman::Rifleman(Context& context)
:   GameObject (context)
{
    setupAnim({10, 18});
}

void Rifleman::tick()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playAnim(Animation::LEFT);
        setVelocity(2.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playAnim(Animation::RIGHT);
        setVelocity(2.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playAnim(Animation::BACK);
        setVelocity(2.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playAnim(Animation::FACE);
        setVelocity(2.f);
    }

    GameObject::tick();

    setVelocity(0.f);
}

void Rifleman::draw()
{
    GameObject::draw();
    m_context.window.draw(m_sprite);
}

void Rifleman::update()
{
    GameObject::update();
    m_sprite.setTexture(TextureManager::get()->load("rifleman.png"));
    m_sprite.setPosition(m_position);
    m_sprite.setColor(m_color);
    m_sprite.setTextureRect(m_animRects[m_anim]);
    m_sprite.setScale(m_scale, m_scale);
}

sf::Vector2f Rifleman::getSize() const
{
    sf::Vector2f size;
    size.x = m_sprite.getGlobalBounds().width;
    size.y = m_sprite.getGlobalBounds().height;
    return size;
}

