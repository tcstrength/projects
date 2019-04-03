#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Context.h"
#include "Config.h"
#include "Info.h"
#include "GUI/Button.h"
#include "Objects/ObjectGroup.h"

class GameEngine
{
public:
    GameEngine(const Config& config);

    void run();

    void begin();

    void end();

    void handleEvents();

private:
    const Config& m_config;
    Context m_context;
    Info m_info;
    ObjectGroup m_group;
};

#endif // GAMEENGINE_H
