#include "Container.h"

uint Container::add(Widget* widget)
{
    m_widgets[m_counter] = widget;
    return m_counter++;
}

void Container::del(uint index)
{
    m_widgets.erase(m_widgets.find(index));
}

void Container::draw()
{
    for (auto it = m_widgets.begin(); it != m_widgets.end(); ++it)
        it->second->draw();
}

void Container::handleEvents()
{
    for (auto it = m_widgets.begin(); it != m_widgets.end(); ++it)
        it->second->handleEvents();
}

