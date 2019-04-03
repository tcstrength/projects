#include "Button.h"

Button::Button(Context& context)
:   Widget(context)
{
    setBorderRadius(4);
    setBorderSize(2);
    setPadding(8, 10);
    setTextString("Push Button");
    setTextSize(22);
    updateState();
}

void Button::updateState()
{
    if (stateIsOn(State::SELECTED))
    {
        setBackgroundColor({200, 200, 200});
        setTextColor(sf::Color::Black);
    }
    else if (stateIsOn(State::PRELIGHT))
    {
        setBackgroundColor({240, 240, 240});
        setTextColor(sf::Color::Black);
    }
    else
    {
        setBackgroundColor({255, 255, 255});
        setTextColor(sf::Color::Black);
    }
}
