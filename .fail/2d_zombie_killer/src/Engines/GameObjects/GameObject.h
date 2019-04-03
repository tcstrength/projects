#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../../Context.h"
#include "../TextureManager.h"
#include "DamageType.h"
#include "../Effects/FadeOut.h"
#include "../Effects/FadeIn.h"

class GameObject : public EffectObject
{
public:

    enum Animation
    {
        FACE  = 0,
        BACK  = 1,
        LEFT  = 2,
        RIGHT = 3,
    };

    GameObject(Context& context);

    virtual ~GameObject();

    virtual void tick();

    virtual void draw();

    virtual void update();

    void playAnim(Animation anim);

    Animation getAnim();

    void setupAnim(sf::Vector2i size = {32, 32});

    const sf::Vector2f& getPosition() const;

    void setPosition(const sf::Vector2f& position);

    const float& getScale() const;

    void setScale(float scale);

    const sf::Color& getColor() const;

    void setColor(const sf::Color& color);

    float getVelocity() const;

    void setVelocity(float velocity);

    void causeDamage(uint dame, float critRate = 0.0, DamageType type = DamageType::Normal);

    bool isDead();

    bool isDone();

protected:
    virtual sf::Vector2f getSize() const = 0;

    Context&     m_context;
    sf::Vector2f m_position;
    float        m_velocity;
    sf::Color    m_color;
    float        m_scale;
    Animation    m_anim;
    sf::IntRect  m_animRects[4];
    float        m_maxHitPoints;
    float        m_hitPoints;
    sf::Sprite   m_HPbar;
    sf::Sprite   m_HPbarBack;
};

#endif // GAMEOBJECT_H
