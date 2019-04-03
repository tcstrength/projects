#include "Widget.h"

Widget::Widget(SDL_Renderer* renderer)
:   _renderer(renderer)
,   _rect({100, 100, 0, 0})
,   _crop({0, 0, 0, 0})
,   _color({255, 255, 255, 255})
,   _state(Unfocused)
,   _lastState(Selected)
,   _hidden(false)
,   _focused(false)
{
    LOG_DEBUG("Create Widget: " << this);
}

Widget::~Widget()
{
    LOG_DEBUG("Delete Widget: " << this);
}

void Widget::setPos(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
    update();
}

void Widget::setSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
    update();
}

void Widget::setRect(int x, int y, int w, int h)
{
    _rect = {x, y, w, h};
    update();
}

void Widget::setRect(const SDL_Rect& newrect)
{
    _rect = newrect;
    update();
}

SDL_Rect Widget::rect()
{
    return _rect;
}

SDL_Rect Widget::crop() const
{
    return _crop;
}

void Widget::setCrop(int x, int y, int w, int h)
{
    _crop = {x, y, w, h};
}

void Widget::setCrop(const SDL_Rect &crop)
{
    _crop = crop;
}

SDL_Color Widget::color() const
{
    return _color;
}

void Widget::setColor(const SDL_Color &color)
{
    _color = color;
    update();
}

void Widget::tick()
{

}

void Widget::draw()
{

}

void Widget::update()
{

}

bool Widget::hitWidget(int mx, int my)
{
    return !_hidden &&
           mx > _rect.x &&
           my > _rect.y &&
           mx < _rect.x + _rect.w &&
            my < _rect.y + _rect.h;
}

void Widget::hide(bool hidden)
{
    _hidden = hidden;
}

bool Widget::hasFocused()
{
    return _focused;
}

void Widget::updateState()
{

}

void Widget::keyPressEvent(SDL_KeyboardEvent &e)
{
}

void Widget::keyReleaseEvent(SDL_KeyboardEvent &e)
{
}

void Widget::mousePressEvent(SDL_MouseButtonEvent &e)
{
    _lastState = _state;

    if (hitWidget(e.x, e.y))
        _state = State::Selected;

    updateState();
}

void Widget::mouseReleaseEvent(SDL_MouseButtonEvent &e)
{
    _lastState = _state;

    if (hitWidget(e.x, e.y))
    {
        _state = State::Released;
        _focused = true;
    }
    else
    {
        _focused = false;
        _state = State::Unfocused;
    }

    updateState();
}

void Widget::mouseMoveEvent(SDL_MouseButtonEvent &e)
{
    _lastState = _state;

    if (_lastState == State::Selected)
        return;

    if (hitWidget(e.x, e.y))
        _state = State::Hovered;
    else
        _state = State::Unfocused;

    updateState();
}
