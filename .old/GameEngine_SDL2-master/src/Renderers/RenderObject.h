#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H


#include "../Interfaces/Drawable.h"
#include "../Interfaces/NonCopyable.h"
#include "../Managers/TextureManager.h"
#include "../Managers/FontManager.h"
#include "../Utils/Log.h"

class RenderObject : public Drawable, NonCopyable
{
public:
    RenderObject();

    virtual     ~RenderObject();

    void        setPos(int x, int y);

    void        setSize(int w, int h);

    SDL_Rect    rect();

    void        setRect(int x, int y, int w, int h);

    void        setRect(const SDL_Rect &newRect);

    SDL_Rect    crop() const;

    void        setCrop(int x, int y, int w, int h);

    void        setCrop(const SDL_Rect &newCrop);

    SDL_Color   color() const;

    void        setColor(const SDL_Color &color);

    void        load(SDL_Renderer* renderer, const char* fileName);

    virtual void tick();

    virtual void draw(SDL_Renderer* renderer);

protected:

    SDL_Texture* _texture;
    SDL_Rect     _rect;
    SDL_Rect     _crop;
    SDL_Color    _color;
    double       _angle;
};

#endif // RENDEROBJECT_H
