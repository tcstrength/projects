#ifndef WIDGET_H
#define WIDGET_H

#include "../../Interfaces/Drawable.h"
#include "../../Interfaces/NonCopyable.h"
#include "../../Utils/Log.h"

class Widget : public Drawable, NonCopyable
{
public:

    enum State
    {
        Hovered,
        Selected,
        Released,
        Unfocused
    };

    Widget(SDL_Renderer* renderer);

    virtual ~Widget();

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

    bool        hitWidget(int mx, int my);

    void        hide(bool hidden = true);

    bool        hasFocused();

    virtual void updateState();

    virtual void update();

    virtual void draw();

    virtual void tick();

    virtual void keyPressEvent(SDL_KeyboardEvent& e);

    virtual void keyReleaseEvent(SDL_KeyboardEvent& e);

    virtual void mousePressEvent(SDL_MouseButtonEvent& e);

    virtual void mouseReleaseEvent(SDL_MouseButtonEvent& e);

    virtual void mouseMoveEvent(SDL_MouseButtonEvent& e);

protected:
    SDL_Renderer* _renderer;
    SDL_Rect _rect;
    SDL_Rect _crop;
    SDL_Color _color;
    State _state;
    State _lastState;
    bool  _hidden;
    bool  _focused;
};

#endif // WIDGET_H
