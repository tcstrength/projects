#include "TextureManager.h"

TextureManager &TextureManager::instance()
{
    static TextureManager txrMan;
    return txrMan;
}

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
    for (auto it = _textures.begin(); it != _textures.end(); ++it)
        SDL_DestroyTexture(it->second);
}

SDL_Texture*  TextureManager::find(const char *fileName)
{
    SDL_Texture* txr = _textures[fileName];

    return txr;
}

SDL_Texture* TextureManager::load(SDL_Renderer* renderer, const char* fileName)
{
    SDL_Texture* txr = _textures[fileName];

    // Check if exists
    if (txr != nullptr)
        return txr;

    txr = IMG_LoadTexture(renderer, fileName);

    if (txr == nullptr)
    {
        LOG_DEBUG("Could not load " << fileName);
        return nullptr;
    }

    _textures[fileName] = txr;

    return txr;
}

void TextureManager::loadList(SDL_Renderer* renderer, const char *listFileName)
{
    std::ifstream inStream(listFileName);
    std::string buffer;

    while(std::getline(inStream, buffer))
        load(renderer, buffer.c_str());
}
