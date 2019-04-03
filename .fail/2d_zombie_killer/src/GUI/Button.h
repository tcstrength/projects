#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"

class Button : public Widget
{

public:
    Button(Context& context);

protected:
    void updateState();

};

#endif // BUTTON_H
