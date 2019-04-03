#ifndef RIFLEMAN_H
#define RIFLEMAN_H

#include "GameObject.h"

class Rifleman : public GameObject
{
public:
    Rifleman(Context& context);

    void tick();

    void draw();

    void update();

protected:
    sf::Vector2f getSize() const;

private:
    sf::Sprite m_sprite;

};

#endif // RIFLEMAN_H
