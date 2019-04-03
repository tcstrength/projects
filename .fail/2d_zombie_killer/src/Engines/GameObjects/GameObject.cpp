#include "GameObject.h"

GameObject::GameObject(Context& context)
:   m_context(context)
,   m_position(sf::Vector2f(0.f, 0.f))
,   m_velocity(0)
,   m_color(sf::Color::White)
,   m_scale(1.f)
,   m_anim(Animation::FACE)
,   m_maxHitPoints(100)
,   m_hitPoints(m_maxHitPoints)
{
    m_HPbar.setTexture(TextureManager::get()->load("hpbar.png"));
    m_HPbarBack.setTexture(TextureManager::get()->load("hpbar_back.png"));

//    FadeIn::get().start(this, 25);
}

GameObject::~GameObject()
{
    LOG_DEBUG("Delete GameObject " << this);
}

const sf::Vector2f& GameObject::getPosition() const
{
    return m_position;
}

void GameObject::setPosition(const sf::Vector2f& position)
{
    m_position = position;
}

void GameObject::playAnim(Animation name)
{
//    LOG_DEBUG(name);
    m_anim = name;
    update();
}

GameObject::Animation GameObject::getAnim()
{
    return m_anim;
}

void GameObject::setupAnim(sf::Vector2i size)
{
    for (int i = 0; i < 4; ++i)
    {
        m_animRects[i].width = size.x;
        m_animRects[i].height = size.y;
        m_animRects[i].left = size.x * i;
        m_animRects[i].top = 0;
    }
}

void GameObject::draw()
{
    m_context.window.draw(m_HPbarBack);
    m_context.window.draw(m_HPbar);
}

void GameObject::update()
{
    sf::Vector2f objSize = getSize();
    sf::FloatRect hpRect = m_HPbarBack.getLocalBounds();
    sf::Vector2f hpPos = getPosition();

    hpPos.x = hpPos.x + objSize.x / 2 - hpRect.width / 2;
    hpPos.y = hpPos.y - 25;

    m_HPbar.setPosition(hpPos);
    m_HPbarBack.setPosition(hpPos);


    sf::IntRect percentRect = {(int)hpRect.left, (int)hpRect.top, (int)(100 * m_hitPoints / m_maxHitPoints), 16};

//    LOG_DEBUG(percentRect.width);

    m_HPbar.setTextureRect(percentRect);
}

const float& GameObject::getScale() const
{
    return m_scale;
}

void GameObject::setScale(float scale)
{
    m_scale = scale;
    update();
}

const sf::Color& GameObject::getColor() const
{
    return m_color;
}

void GameObject::setColor(const sf::Color& color)
{
    m_color = color;
    update();
}

float GameObject::getVelocity() const
{
    return m_velocity;
}

void GameObject::setVelocity(float velocity)
{
    m_velocity = velocity;
}

void GameObject::causeDamage(uint dame, float critRate, DamageType type)
{
    int perc = critRate * 100;

    switch(type)
    {
        case DamageType::Fire:
            dame *= 2.0;
            break;

        case DamageType::Eletric:
            dame *= 1.5;
            break;

        case DamageType::Normal:
            dame *= 1.0;
            break;

        default:
            break;
    }

    if (rand() % 100 < perc)
        dame *= 2.0;

    if (m_hitPoints > 0)
    {
        m_hitPoints -= dame;
        FadeOut::get().start(this, 5);

        if (m_hitPoints <= 0)
        {
            m_hitPoints = 0;
            FadeOut::get().start(this);
        }
    }
}

bool GameObject::isDead()
{
    return m_hitPoints == 0;
}

bool GameObject::isDone()
{
    return m_hitPoints == 0 && FadeOut::get().isDone(this);
}

void GameObject::tick()
{
    switch(m_anim)
    {
        case Animation::FACE:
            m_position.y += m_velocity;
            break;

        case Animation::BACK:
            m_position.y -= m_velocity;
            break;

        case Animation::LEFT:
            m_position.x -= m_velocity;
            break;

        case Animation::RIGHT:
            m_position.x += m_velocity;
            break;

        default:
            break;
    }

//    if (m_damagedEffTick >= 0)
//    {
//        sf::Uint8 rg = 255 - sf::Uint8(128* (float)m_damagedEffTick / (float)m_damagedEffMaxTick);
//        setColor(sf::Color{255, rg, rg});
//        --m_damagedEffTick;
//    }

    update();
}




