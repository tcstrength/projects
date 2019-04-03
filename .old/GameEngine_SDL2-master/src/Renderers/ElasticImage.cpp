#include "ElasticImage.h"

void ElasticImage::draw(SDL_Renderer *renderer)
{
    static SDL_Rect center   = { 8,  8, 16, 16};
    static SDL_Rect corners[4]  =
    {
        { 0,  0, 8, 8}, // top Left
        {24,  0, 8, 8}, // top Right
        { 0, 24, 8, 8}, // bottom Left
        {24, 24, 8, 8}, // bottom Right
    };

    static SDL_Rect lines[4] =
    {
        { 8,  0, 8, 8}, // top line
        {24,  8, 8, 8}, // right line
        { 8, 24, 8, 8}, // bot line
        { 0,  8, 8, 8}, // left line
    };

    SDL_Rect cornerRects[4] =
    {
        {_rect.x                , _rect.y               , 8, 8},
        {_rect.x + _rect.w - 8  , _rect.y               , 8, 8},
        {_rect.x                , _rect.y + _rect.h - 8 , 8, 8},
        {_rect.x + _rect.w - 8  , _rect.y + _rect.h - 8 , 8, 8}
    };

    SDL_Rect lineRects[4] =
    {
        {_rect.x + 8            , _rect.y               , _rect.w - 16  , 8},
        {_rect.x + _rect.w - 8  , _rect.y + 8           , 8             , _rect.h - 16},
        {_rect.x + 8            , _rect.y + _rect.h - 8 , _rect.w - 16  , 8},
        {_rect.x                , _rect.y + 8           , 8             , _rect.h - 16}
    };

    SDL_Rect centerRect = {_rect.x + 8, _rect.y + 8, _rect.w - 16, _rect.h - 16};

    SDL_SetTextureColorMod(_texture, _color.r, _color.g, _color.b);
    SDL_SetTextureAlphaMod(_texture, _color.a);

    for (int i = 0; i < 4; ++i)
    {
        SDL_RenderCopyEx(renderer, _texture, &corners[i], &cornerRects[i], 0, nullptr, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, _texture, &lines[i], &lineRects[i], 0, nullptr, SDL_FLIP_NONE);
    }

    SDL_RenderCopyEx(renderer, _texture, &center, &centerRect, 0, nullptr, SDL_FLIP_NONE);

    // Reset color for next draw
    SDL_SetTextureColorMod(_texture, 255, 255, 255);
    SDL_SetTextureAlphaMod(_texture, 255);
}
