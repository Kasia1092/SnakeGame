#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "GraphicObject.h"


class Leaderboard : public GraphicObject
{
public:

    Leaderboard(std::shared_ptr<Context>& context);
    ~Leaderboard();

    void init() override;
    void draw() override;
    void input() override;

    void update(const sf::Time& time) override;


private:
    std::shared_ptr<Context> context;
    sf::Sprite wallpaper;

    sf::Text title;
    sf::Text b[10];
    sf::Text nr[10];
    
    bool isMenuButtonPressed;
};

