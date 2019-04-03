#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "Text.h"
#include "../../Renderers/ElasticImage.h"

class LineEdit : public Widget
{
public:
    LineEdit(SDL_Renderer* renderer);

    virtual ~LineEdit();

    void draw();

    void update();

    void updateState();

    void keyPressEvent(SDL_KeyboardEvent& e);

private:
    Text* _text;
    Text* _cursor;
    ElasticImage* _image;
};

#endif // LINEEDIT_H
