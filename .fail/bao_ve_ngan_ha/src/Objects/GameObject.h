#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Context.h"
#include "../Managers/TextureManager.h"
#include "GameObjectType.h"

class GameObject
{
public:
    GameObject(Context& context);

    virtual ~GameObject();

    virtual void tick();

    virtual void draw();

    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f &position);

    sf::Color getColor() const;

    void setColor(const sf::Color &color);

    float getScale() const;

    void setScale(float scale);

protected:
    void load(const char* fileName, GameObjectType type);

    virtual void update();

protected:
    Context&       m_context;
    sf::Vector2f   m_position;
    sf::Color      m_color;
    GameObjectType m_type;
    sf::Sprite     m_sprite;
    float          m_scale;
};

#endif // GAMEOBJECT_H
