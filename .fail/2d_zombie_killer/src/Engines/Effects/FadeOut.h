#ifndef FADEOUT_H
#define FADEOUT_H

#include "EffectTick.h"
#include <map>

class FadeOut
{
public:

    static FadeOut& get();

    void start(EffectObject* object, uint max = 50);

    void remove(EffectObject* object);

    void tick();

    bool isDone(EffectObject* object);

private:
    FadeOut();
    std::map<EffectObject*, EffectTick> m_effects;
};

#endif // FADEOUT_H
