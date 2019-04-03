#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <vector>
#include "../Context.h"

class TextureManager
{
public:
    static TextureManager* get();

    sf::Texture& load(const char* fileName);

private:
    TextureManager();

    std::map<std::string, sf::Texture> m_textureMap;
};

#endif // TEXTUREMANAGER_H