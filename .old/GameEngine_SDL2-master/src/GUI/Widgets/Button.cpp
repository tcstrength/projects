#include "Button.h"

Button::Button(SDL_Renderer* renderer)
:   Widget(renderer)
,   _text(new Text(renderer))
,   _image(new ElasticImage)
{
    _image->load(renderer, "textures/button.png");

    setSize(200, 40);
    setTextMsg("Push Button");
    update();
    updateState();
}

Button::~Button()
{
    delete _text;
    delete _image;
}

void Button::setTextMsg(std::string textMsg)
{
    _text->setTextMsg(textMsg);
    update();
}

std::string Button::textMsg()
{
    return _text->textMsg();
}

void Button::setFontSize(uint size)
{
    _text->setFontSize(size);
    update();
}

uint Button::fontSize()
{
    return _text->fontSize();
}

void Button::draw()
{
    if (_hidden == true)
        return;

    _image->draw(_renderer);
    _text->draw();
}

void Button::update()
{

    int textX = _rect.x + _rect.w / 2 - _text->rect().w / 2;
    int textY = _rect.y + _rect.h / 2 - _text->rect().h / 2;

    _image->setRect(_rect);
    _image->setColor(_color);
    _text->setPos(textX, textY);
}

void Button::updateState()
{
    if (_lastState == _state)
        return;

    switch(_state)
    {

    case State::Selected:
        setColor({51, 153, 255, 255});
        _text->setColor({255, 255, 255, 255});
        break;

    case State::Released:
    case State::Hovered:
        setColor({75, 75, 75, 255});
        _text->setColor({155, 220, 255, 255});
        break;

    case State::Unfocused:
        setColor({75, 75, 75, 255});
        _text->setColor({140, 205, 255, 255});
        break;
    }
}
