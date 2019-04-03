#include "GameObject.h"

GameObject::GameObject(Context &context)
:   m_context(context)
,   m_position(sf::Vector2f(0.f, 0.f))
,   m_color(sf::Color::White)
,   m_type(GameObjectType::ENEMY)
{

}

GameObject::~GameObject()
{

}

void GameObject::tick()
{

}

void GameObject::draw()
{
    m_context.window.draw(m_sprite);
}

void GameObject::load(const char *fileName, GameObjectType type)
{
    m_sprite.setTexture(TextureManager::instance()->get(fileName));
    m_type = type;
}

void GameObject::update()
{
    m_sprite.setPosition(m_position);
    m_sprite.setColor(m_color);
    m_sprite.setScale(m_scale, m_scale);
}

sf::Vector2f GameObject::getPosition() const
{
    return m_position;
}

void GameObject::setPosition(const sf::Vector2f &position)
{
    m_position = position;
    update();
}

sf::Color GameObject::getColor() const
{
    return m_color;
}

void GameObject::setColor(const sf::Color &color)
{
    m_color = color;
    update();
}

float GameObject::getScale() const
{
    return m_scale;
}

void GameObject::setScale(float scale)
{
    m_scale = scale;
    update();
}
