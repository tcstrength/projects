#ifndef TEXT_H
#define TEXT_H

#include "Widget.h"
#include "../../Managers/FontManager.h"

class Text : public Widget
{
public:
    Text(SDL_Renderer* renderer);

    virtual ~Text();

    void limitTextLength(uint length);

    void setTextMsg(std::string newText);

    std::string textMsg();

    void setFontSize(uint size = FONT_DEFAULT_SIZE);

    uint fontSize();

    void update();

    void draw();

//    void mouseMoveEvent(SDL_MouseButtonEvent& e);

protected:
    SDL_Texture* _texture;
    uint _fontSize;
    uint _limitedLength;
    std::string _textMsg;
};

#endif // TEXT_H
