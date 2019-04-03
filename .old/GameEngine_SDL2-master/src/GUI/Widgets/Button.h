#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"
#include "Text.h"
#include "../../Managers/TextureManager.h"
#include "../../Renderers/ElasticImage.h"

class Button : public Widget
{
public:
    Button(SDL_Renderer* renderer);

    virtual ~Button();

    void setTextMsg(std::string textMsg);

    std::string textMsg();

    void setFontSize(uint size = FONT_DEFAULT_SIZE);

    uint fontSize();

    void draw();

    void update();

    void updateState();

private:

    Text* _text;
    ElasticImage* _image;
};

#endif // BUTTON_H
