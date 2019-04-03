#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <vector>
#include "../Utils/Log.h"
#define FONT_DEFAULT_PATH "fonts/SFPro.ttf"
#define FONT_DEFAULT_SIZE 18

class FontManager
{
public:
    static FontManager* instance();

    TTF_Font* font(uint size = FONT_DEFAULT_SIZE);

private:
    FontManager();

    ~FontManager();

    std::vector<TTF_Font*> _fonts;
};

#endif // FONTMANAGER_H
