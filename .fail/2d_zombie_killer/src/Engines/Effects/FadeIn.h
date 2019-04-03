#ifndef FADEIN_H
#define FADEIN_H

#include "EffectTick.h"

class FadeIn
{
public:

    static FadeIn& get();

    void start(EffectObject* object, uint max = 25);

    void remove(EffectObject* object);

    void tick();

    bool isDone(EffectObject* object);

private:
    FadeIn();
    std::map<EffectObject*, EffectTick> m_effects;
};

#endif // FADEIN_H
