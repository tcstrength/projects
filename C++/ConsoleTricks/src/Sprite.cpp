#include "Sprite.h"

Sprite::Sprite(const std::vector<std::string>& data)
:   m_posX(0)
,   m_posY(0)
{
    for (uint i = 0; i < data.size(); ++i)
    {
        m_data.push_back(data[i]);
    }
}

void Sprite::render(Screen &screen)
{
    for (uint i = 0; i < m_data.size(); ++i)
    {
        screen.putString(m_data[i], m_posX, m_posY + i);
    }
}

uint Sprite::getPosX() const
{
    return m_posX;
}

void Sprite::setPosX(const uint& posX)
{
    m_posX = posX;
}

uint Sprite::getPosY() const
{
    return m_posY;
}

void Sprite::setPosY(const uint& posY)
{
    m_posY = posY;
}
