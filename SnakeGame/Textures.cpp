#include "Textures.h"


Textures::Textures()
{
}


Textures::~Textures()
{
}

void Textures::addTexture(int id, const std::string& filePath, bool wantRepeated)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(wantRepeated);
        textures[id] = std::move(texture);
    }
}


void Textures::addFont(int id, const std::string& filePath)
{
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filePath))
    {
        fonts[id] = std::move(font);
    }
}


const sf::Texture& Textures::getTexture(int id) const
{
    return *(textures.at(id).get());
}


const sf::Font& Textures::getFont(int id) const
{
    return *(fonts.at(id).get());
}