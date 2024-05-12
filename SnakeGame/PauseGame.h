#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GraphicObject.h"
#include "Game.h"



class PauseGame : public GraphicObject
{
public:
    PauseGame(std::shared_ptr<Context>& context);
    ~PauseGame();

    void init() override;
    void draw() override;
    void input() override;
    void update(const sf::Time& time) override;
    

private:
    std::shared_ptr<Context> context;
    sf::Text pauseTitle;
};
