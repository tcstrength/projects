#ifndef INFO_H
#define INFO_H

#include "Config.h"
#include "Context.h"
#include "GUI/Widget.h"

class Info
{
public:
    Info(Context& context, const Config& config);

    void update();

    void draw();
private:
    const Config& m_config;
    Context& m_context;
    sf::Clock m_clock;
    sf::Text m_fpsText;
};

#endif // INFO_H
