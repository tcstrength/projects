#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "GameObject.h"

class BasicEnemy : public GameObject
{

public:
    BasicEnemy(Context& context);

    void draw();

    void update();

protected:
    sf::Vector2f getSize() const;

private:
    sf::Sprite m_sprite;

};

#endif // BASICENEMY_H
