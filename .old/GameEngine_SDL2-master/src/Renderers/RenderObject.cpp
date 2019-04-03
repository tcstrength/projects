#include "RenderObject.h"

RenderObject::RenderObject()
:   _texture(nullptr)
,   _rect({0, 0, 0, 0})
,   _crop({0, 0, 0, 0})
,   _color({255, 255, 255, 255})
,   _angle(0)
{
    LOG_DEBUG("Create RenderObject " << this);
}

RenderObject::~RenderObject()
{
    LOG_DEBUG("Delete RenderObject " << this);
}

void RenderObject::load(SDL_Renderer *renderer, const char *fileName)
{
    _texture = TextureManager::instance().load(renderer, fileName);
    SDL_QueryTexture(_texture, nullptr, nullptr, &_crop.w, &_crop.h);

    if (_rect.w < _crop.w)
        _rect.w = _crop.w;

    if (_rect.h < _crop.h)
        _rect.h = _crop.h;
}

void RenderObject::tick()
{

}

void RenderObject::draw(SDL_Renderer *renderer)
{
    SDL_SetTextureColorMod(_texture, _color.r, _color.g, _color.b);
    SDL_SetTextureAlphaMod(_texture, _color.a);
    SDL_RenderCopyEx(renderer, _texture, &_crop, &_rect, _angle, nullptr, SDL_FLIP_NONE);
    SDL_SetTextureColorMod(_texture, 255, 255, 255);
    SDL_SetTextureAlphaMod(_texture, 255);
}

void RenderObject::setPos(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

void RenderObject::setSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}

void RenderObject::setRect(int x, int y, int w, int h)
{
    _rect = {x, y, w, h};
}

void RenderObject::setRect(const SDL_Rect& newrect)
{
    _rect = newrect;
}

SDL_Rect RenderObject::rect()
{
    return _rect;
}

SDL_Rect RenderObject::crop() const
{
    return _crop;
}

void RenderObject::setCrop(int x, int y, int w, int h)
{
    _crop = {x, y, w, h};
}

void RenderObject::setCrop(const SDL_Rect &crop)
{
    _crop = crop;
}

SDL_Color RenderObject::color() const
{
    return _color;
}

void RenderObject::setColor(const SDL_Color &color)
{
    _color = color;
}
