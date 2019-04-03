#ifndef CONTAINER_H
#define CONTAINER_H

#include "Widget.h"
#include <map>


class Container
{
public:
    uint add(Widget* widget);

    void del(uint index);

    void handleEvents();

    void draw();

private:
    uint m_counter;
    std::map<uint, Widget*> m_widgets;
};

#endif // CONTAINER_H
