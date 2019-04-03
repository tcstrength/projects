#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../Context.h"
#include "GameHandler.h"

class GameEngine
{
public:
    GameEngine(Context& context, const Config& config);

    void tick();

    void draw();

    void handleEvents();
private:
    const Config&     m_config;
          Context&    m_context;
          GameHandler m_handler;
};

#endif // GAMEENGINE_H
