#ifndef CONTEXT_H
#define CONTEXT_H

#include "Config.h"
#include "Utils/Log.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Renderers/RoundedRectangleShape.h"

struct Context
{
    Context(const Config& config);

    sf::RenderWindow window;
    sf::Font font;
    sf::Event event;
};

#endif // CONTEXT_H
