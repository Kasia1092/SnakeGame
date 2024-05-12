#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GraphicObject.h"
#include "Game.h"

class MainMenu : public GraphicObject
{
private:
    std::shared_ptr<Context> context;
    sf::Text gameTitle;
    sf::Text gamesecTitle;
    sf::Text playButton;
    sf::Text exitButton;
    sf::Text instructionButton;
    sf::Text leaderboardButton;

    sf::Sprite smenu;

    bool isPlayButtonSelected;
    bool isPlayButtonPressed;

    bool isExitButtonSelected;
    bool isExitButtonPressed;

    bool isInstructionButtonSelected;
    bool isInstructionButtonPressed;

    bool isLeaderboardButtonSelected;
    bool isLeaderboardButtonPressed;

public:
    MainMenu(std::shared_ptr<Context>& context);
    ~MainMenu();

    void init() override;
    void draw() override;
    void input() override;
    void update(const sf::Time& time) override;
   
};
