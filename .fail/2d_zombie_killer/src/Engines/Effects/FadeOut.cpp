#include "FadeOut.h"

FadeOut::FadeOut()
{

}

FadeOut& FadeOut::get()
{
    static FadeOut fo;
    return fo;
}

void FadeOut::start(EffectObject* object, uint max)
{
    if (object != nullptr)
    {
        m_effects[object] = {max, max};
    }
}

void FadeOut::remove(EffectObject* object)
{
    auto it = m_effects.find(object);

    if (it != m_effects.end())
    {
        m_effects.erase(it);
    }
}

void FadeOut::tick()
{
    for (auto it = m_effects.begin(); it != m_effects.end(); ++it)
    {
        if (--it->second.tick > it->second.maxTick)
            continue;

        if (it->second.tick > 0)
        {
            sf::Color color = it->first->getColor();
            color.a = (255 * (float)it->second.tick / (float)it->second.maxTick);
            it->first->setColor(color);
//            LOG_DEBUG(it->second.tick << ", " << it->second.maxTick);
            --it->second.tick;
        }
        else
        {
            sf::Color color = it->first->getColor();
            color.a = 255;
            it->first->setColor(color);
            remove(it->first);
        }
    }
}

bool FadeOut::isDone(EffectObject* object)
{
    return m_effects[object].tick == 0;
}
