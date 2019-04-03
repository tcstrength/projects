#include "LineEdit.h"

LineEdit::LineEdit(SDL_Renderer* renderer)
:   Widget(renderer)
,   _text(new Text(renderer))
,   _cursor(new Text(renderer))
,   _image(new ElasticImage)
{
    _image->load(renderer, "textures/lineEdit.png");
    _text->setTextMsg("Line Edit");
    _cursor->setTextMsg("|");
    update();
    updateState();
}

LineEdit::~LineEdit()
{
    delete _text;
    delete _cursor;
    delete _image;
}

void LineEdit::updateState()
{
    if (hasFocused())
    {
        _cursor->hide(false);
        _text->setColor({255, 255, 255, 255});
        _image->setColor({51, 153, 255, 255});
    } else
    {
        _cursor->hide();
        _text->setColor({140, 205, 255, 255});
        _image->setColor({90, 90, 90, 255});
    }
}

void LineEdit::draw()
{
    _image->draw(_renderer);
    _cursor->draw();
    _text->draw();
}

void LineEdit::keyPressEvent(SDL_KeyboardEvent &e)
{
    if (_focused == false)
        return;

    bool isAlp =
    {
        (e.keysym.sym >= '0' && e.keysym.sym <= '9') ||
        (e.keysym.sym >= 'a' && e.keysym.sym <= 'z') ||
        (e.keysym.sym == ' ')
    };

    std::string temp = _text->textMsg();

    if (e.keysym.sym == SDLK_BACKSPACE && temp.size() > 0)
        temp.pop_back();

    if (isAlp)
        temp.push_back((char)e.keysym.sym);

    _text->setTextMsg(temp);

    if (_text->rect().w > _rect.w - 24)
        temp.pop_back();

    _text->setTextMsg(temp);
    update();
}

void LineEdit::update()
{
    if (_rect.h < 40)
        _rect.h = 40;

    if (_rect.w < 200)
        _rect.w = 400;

    int textX = _rect.x + 8;
    int textY = _rect.y + _rect.h / 2 - _text->rect().h / 2 - 2;

    if (_text->textMsg().length() == 0)
        _cursor->setPos(_rect.x + 8, textY);
    else
        _cursor->setPos(textX + _text->rect().w, textY);

    _image->setRect(_rect);
    _text->setPos(textX, textY);
}
