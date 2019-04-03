#ifndef SPRITE_H
#define SPRITE_H

#include "Screen.h"

class Sprite
{
public:
    Sprite(const std::vector<std::string>& data);

    void render(Screen& screen);

    uint getPosX() const;

    void setPosX(const uint& posX);

    uint getPosY() const;

    void setPosY(const uint& posY);

private:
    std::vector<std::string> m_data;
    uint m_posX;
    uint m_posY;
};

#endif // SPRITE_H
