#ifndef APPLICATION_H
#define APPLICATION_H

#include "Context.h"
#include "Config.h"
#include "Info.h"
#include "GUI/Button.h"

class Application
{
public:
    Application(const Config& config);

    void run();

    void begin();

    void end();

    void handleEvents();

private:
    const Config& m_config;
    Context m_context;
    Info m_info;

};

#endif // APPLICATION_H
