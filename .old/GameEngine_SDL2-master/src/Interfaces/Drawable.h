#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Drawable
{
public:
    virtual void draw(SDL_Renderer*);
};

#endif // DRAWABLE_H
