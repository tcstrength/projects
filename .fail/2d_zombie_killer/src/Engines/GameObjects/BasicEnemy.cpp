#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(Context& context)
:   GameObject(context)
{
    setupAnim(sf::Vector2i(10, 23));
}

void BasicEnemy::update()
{
    GameObject::update();
    m_sprite.setTexture(TextureManager::get()->load("zombie.png"));
    m_sprite.setPosition(m_position);
    m_sprite.setColor(m_color);
    m_sprite.setTextureRect(m_animRects[m_anim]);
    m_sprite.setScale(m_scale, m_scale);
}

sf::Vector2f BasicEnemy::getSize() const
{
    sf::Vector2f size;
    size.x = m_sprite.getGlobalBounds().width;
    size.y = m_sprite.getGlobalBounds().height;
    return size;
}

void BasicEnemy::draw()
{
    GameObject::draw();
    m_context.window.draw(m_sprite);
}
