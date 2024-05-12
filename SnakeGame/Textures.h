#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>


    class Textures
    {
    public:
        Textures();
        ~Textures();

        void addTexture(int id, const std::string& filePath, bool wantRepeated = false);
        void addFont(int id, const std::string& filePath);

        const sf::Texture& getTexture(int id) const;
        const sf::Font& getFont(int id) const;

    private:
        std::map<int, std::unique_ptr<sf::Texture>> textures;
        std::map<int, std::unique_ptr<sf::Font>> fonts;
    };

