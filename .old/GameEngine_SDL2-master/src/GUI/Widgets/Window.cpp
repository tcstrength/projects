#include "Window.h"

Window::Window(const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        LOG_ERROR("Could not initialize video " << SDL_GetError());
        return;
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_WEBP | IMG_INIT_TIF) < 0)
    {
        LOG_ERROR("Could not initialize img " << IMG_GetError());
        return;
    }

    if (TTF_Init() < 0)
    {
        LOG_ERROR("Could not initialize ttf " << TTF_GetError());
    }

    _window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    if (_window == nullptr)
    {
        LOG_ERROR("Could not create window " << SDL_GetError());
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (_renderer == nullptr)
    {
        LOG_ERROR("Could not create renderer " << SDL_GetError());
        return;
    }

    _event = new SDL_Event;
}

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Window::loop()
{
    bool running = true;
    SDL_Texture* background = TextureManager::instance().load(_renderer, "textures/background.png");

    while (running)
    {
        while (SDL_PollEvent(_event))
        {
            switch(_event->type)
            {

            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                keyPressEvent(_event->key);
                break;

            case SDL_KEYUP:
                keyReleaseEvent(_event->key);
                break;

            case SDL_MOUSEBUTTONDOWN:
                mousePressEvent(_event->button);
                break;

            case SDL_MOUSEBUTTONUP:
                mouseReleaseEvent(_event->button);
                break;

            case SDL_MOUSEMOTION:
                mouseMoveEvent(_event->button);
                break;

            default: break;
            }
        }

        SDL_RenderClear(_renderer);
        SDL_RenderCopy(_renderer, background, nullptr, nullptr);

        tick();
        draw();


        SDL_RenderPresent(_renderer);
    }
}

void Window::connect(void (*callback)())
{
    if (callback != nullptr)
        _cbFuncs.push_back(callback);
}

void Window::addWidget(Widget *widget)
{
    if (widget != nullptr)
        _widgets.push_back(widget);
}

void Window::delWidget(Widget* widget)
{
    if (widget == nullptr)
        return;

    for (auto it = _widgets.begin(); it != _widgets.end(); ++it)
        if ((*it) == widget)
            _widgets.erase(it);

    delete widget;
}

void Window::update()
{
}

void Window::tick()
{
    for (auto cbfunc : _cbFuncs)
        cbfunc();

    for (auto w : _widgets)
        w->tick();
}

void Window::draw()
{
    for (auto w : _widgets)
        w->draw();
}

void Window::keyPressEvent(SDL_KeyboardEvent &e)
{
    for (auto w : _widgets)
        w->keyPressEvent(e);
}

void Window::keyReleaseEvent(SDL_KeyboardEvent &e)
{
    for (auto w : _widgets)
        w->keyReleaseEvent(e);
}

void Window::mousePressEvent(SDL_MouseButtonEvent &e)
{
    for (auto w : _widgets)
        w->mousePressEvent(e);
}

void Window::mouseReleaseEvent(SDL_MouseButtonEvent &e)
{
    for (auto w : _widgets)
        w->mouseReleaseEvent(e);
}

void Window::mouseMoveEvent(SDL_MouseButtonEvent &e)
{
    for (auto w : _widgets)
        w->mouseMoveEvent(e);
}

SDL_Renderer *Window::renderer() const
{
    return _renderer;
}
