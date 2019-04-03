#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet : public GameObject
{
public:
    Bullet(Context& context);

    void draw();

    void tick();

    void update();

protected:
    sf::Vector2f getSize() const;

private:
    sf::Sprite m_sprite;
};

#endif // BULLET_H
