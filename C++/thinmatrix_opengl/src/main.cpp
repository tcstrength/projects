#include "RenderEngine/Display.h"

int main()
{
    renderEngine::Config config;
    renderEngine::Display::create(config);

    while(renderEngine::Display::isOpen())
    {
        renderEngine::Display::update();
    }

    return 0;
}
