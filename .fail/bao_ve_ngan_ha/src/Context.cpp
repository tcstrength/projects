#include "Context.h"

Context::Context(const Config& config)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    if (config.isFullscreen)
    {
        window.create(sf::VideoMode::getDesktopMode(), config.title, sf::Style::Fullscreen, settings);
    }
    else
    {
        sf::VideoMode videoMode(config.width, config.height);
        window.create(videoMode, config.title, sf::Style::Default, settings);
    }

    window.setVerticalSyncEnabled(config.vsyncEnabled);
    window.setFramerateLimit(config.frameRate);

    font.loadFromFile("fonts/SFPro.otf");
}
