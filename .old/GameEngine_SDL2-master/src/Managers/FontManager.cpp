#include "FontManager.h"

FontManager::FontManager()
{
    LOG_DEBUG("Open FontManager " << this);

    for (int i = 0; i < 48; ++i)
        _fonts.push_back(TTF_OpenFont(FONT_DEFAULT_PATH, i + 1));
}

FontManager::~FontManager()
{
    LOG_DEBUG("Close FontManager " << this);

    for (auto f : _fonts)
        TTF_CloseFont(f);
}

FontManager* FontManager::instance()
{
    static FontManager fm;

    return &fm;
}

TTF_Font* FontManager::font(uint size)
{
    if (size <= 0)
        return _fonts[0];

    if (size > _fonts.size())
        return _fonts[47];

    return _fonts[size - 1];
}
