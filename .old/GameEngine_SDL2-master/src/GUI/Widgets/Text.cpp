#include "Text.h"

Text::Text(SDL_Renderer *renderer)
:   Widget(renderer)
,   _texture(nullptr)
,   _fontSize(FONT_DEFAULT_SIZE)
,   _textMsg("Text Message")
,   _limitedLength(0)
{
    update();
}

Text::~Text()
{
    SDL_DestroyTexture(_texture);
}

void Text::limitTextLength(uint length)
{
    _limitedLength = length;
}

void Text::setTextMsg(std::string newText)
{

    if (_limitedLength != 0 && newText.length() >= _limitedLength)
        while (newText.length() > _limitedLength)
            newText.pop_back();

    _textMsg = newText;
    update();
}

std::string Text::textMsg()
{
    return _textMsg;
}

void Text::setFontSize(uint size)
{
    _fontSize = size;
    update();
}

uint Text::fontSize()
{
    return _fontSize;
}

void Text::draw()
{
    if (_hidden == true)
        return;

    SDL_RenderCopyEx(_renderer, _texture, &_crop, &_rect, 0, nullptr, SDL_FLIP_NONE);
}

void Text::update()
{
    if (_texture != nullptr)
    {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
    }

    TTF_Font* font = FontManager::instance()->font(_fontSize);
    SDL_Surface* surf = TTF_RenderUTF8_Blended(font, _textMsg.c_str(), _color);

    _texture = SDL_CreateTextureFromSurface(_renderer, surf);

    SDL_QueryTexture(_texture, nullptr, nullptr, &_crop.w, &_crop.h);
    _rect.w = _crop.w;
    _rect.h = _crop.h;

    SDL_FreeSurface(surf);

    SDL_SetTextureColorMod(_texture, _color.r, _color.g, _color.b);
    SDL_SetTextureAlphaMod(_texture, _color.a);
}

//void Text::mouseMoveEvent(SDL_MouseButtonEvent &e)
//{
//    Uint8 r = rand() % 255;
//    Uint8 g = rand() % 255;
//    Uint8 b = rand() % 255;

//    if (hitWidget(e.x, e.y))
//        setColor({r, g, b, 255});
//}
