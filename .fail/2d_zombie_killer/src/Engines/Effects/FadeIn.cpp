#include "FadeIn.h"

FadeIn::FadeIn()
{

}

FadeIn& FadeIn::get()
{
    static FadeIn fo;
    return fo;
}

void FadeIn::start(EffectObject* object, uint max)
{
    if (object != nullptr)
    {
        m_effects[object] = {0, max};
    }
}

void FadeIn::remove(EffectObject* object)
{
    auto it = m_effects.find(object);

    if (it != m_effects.end())
    {
        m_effects.erase(it);
    }
}

void FadeIn::tick()
{
    for (auto it = m_effects.begin(); it != m_effects.end(); ++it)
    {
        if (it->second.tick < it->second.maxTick)
        {
            sf::Color color = it->first->getColor();
            color.a = (255 * (float)it->second.tick / (float)it->second.maxTick);
            it->first->setColor(color);
//            LOG_DEBUG(it->second.tick << ", " << it->second.maxTick);
            ++it->second.tick;
        }
        else
        {
            remove(it->first);
        }
    }
}

bool FadeIn::isDone(EffectObject* object)
{
    return m_effects[object].tick == m_effects[object].maxTick;
}
