#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GraphicObject.h"
#include "Game.h"


class GameOver : public GraphicObject
{
public:
    GameOver(std::shared_ptr<Context>& context);
    ~GameOver();

    void init() override;
    void draw() override;
    void input() override;
    void update(const sf::Time& time) override;
  

private:
    std::shared_ptr<Context> context;
    sf::Text gameOverTitle;
    sf::Text retryButton;
    sf::Text menuButton;
    sf::Text exitButton;

    sf::Sprite gover;

    bool isRetryButtonSelected;
    bool isRetryButtonPressed;


    bool isMenuButtonSelected;
    bool isMenuButtonPressed;

    bool isExitButtonSelected;
    bool isExitButtonPressed;
};