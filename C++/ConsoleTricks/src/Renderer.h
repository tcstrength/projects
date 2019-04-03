#ifndef RENDERER_H
#define RENDERER_H

#include "Screen.h"
#include "Sprite.h"

class Renderer
{
public:
    Renderer(Screen& screen);

    void render(Sprite& sprite);
private:
    Screen& m_screen;
};

#endif // RENDERER_H
