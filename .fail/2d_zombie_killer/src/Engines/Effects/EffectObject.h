#ifndef EFFECTOBJECT_H
#define EFFECTOBJECT_H

#include "../../Context.h"

class EffectObject
{
public:
    virtual const sf::Color& getColor() const = 0;

    virtual void setColor(const sf::Color& color) = 0;
};

#endif // EFFECTOBJECT_H
