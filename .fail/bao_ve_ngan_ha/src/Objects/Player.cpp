#include "Player.h"

Player::Player(Context &context)
:   GameObject(context)
{
    load("character.png", GameObjectType::PLAYER);
    setPosition(sf::Vector2f(500.f, 500.f));
    setScale(8.f);
}

void Player::tick()
{
    sf::Vector2f pos = (sf::Vector2f)sf::Mouse::getPosition(m_context.window);
    pos.x = pos.x - 32;
    pos.y = pos.y - 32;
    setPosition(pos);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        LOG_DEBUG("Bang!");
    }
}
