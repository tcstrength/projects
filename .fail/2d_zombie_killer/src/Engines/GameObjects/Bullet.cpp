#include "Bullet.h"

Bullet::Bullet(Context& context)
:   GameObject (context)
{
    setVelocity(5.f);
    setupAnim({16, 16});
}

void Bullet::tick()
{
    GameObject::tick();
    causeDamage(1);
}

void Bullet::draw()
{
    m_context.window.draw(m_sprite);
}

void Bullet::update()
{
    GameObject::update();
    m_sprite.setTexture(TextureManager::get()->load("bullet.png"));
    m_sprite.setPosition(m_position);
    m_sprite.setColor(m_color);
    m_sprite.setTextureRect(m_animRects[m_anim]);
    m_sprite.setScale(m_scale, m_scale);
}

sf::Vector2f Bullet::getSize() const
{
    sf::Vector2f size;
    size.x = m_sprite.getGlobalBounds().width;
    size.y = m_sprite.getGlobalBounds().height;
    return size;
}
