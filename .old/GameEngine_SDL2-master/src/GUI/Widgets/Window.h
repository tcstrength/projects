#ifndef WINDOW_H
#define WINDOW_H

#include <unordered_map>
#include <list>
#include <vector>
#include "../../Managers/TextureManager.h"
#include "Widget.h"

class Window
{
public:
    Window(const char* title, int width, int height);

    ~Window();

    void loop();

    void connect(void(*)());

    void addWidget(Widget* widget);

    void delWidget(Widget* widget);

    SDL_Renderer *renderer() const;

private:
    void update();

    void tick();

    void draw();

    void keyPressEvent(SDL_KeyboardEvent& e);

    void keyReleaseEvent(SDL_KeyboardEvent& e);

    void mousePressEvent(SDL_MouseButtonEvent& e);

    void mouseReleaseEvent(SDL_MouseButtonEvent& e);

    void mouseMoveEvent(SDL_MouseButtonEvent& e);

private:
    SDL_Renderer* _renderer;
    SDL_Window* _window;
    SDL_Event* _event;
    std::vector<void(*)()> _cbFuncs;
    std::vector<Widget*> _widgets;
};

#endif // WINDOW_H
