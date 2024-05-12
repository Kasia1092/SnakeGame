#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GraphicObject.h"
#include "Game.h"



class Instruction : public GraphicObject
{
public:
    Instruction(std::shared_ptr<Context>& context);
    ~Instruction();

    void init() override;
    void draw() override;
    void input() override;
    void update(const sf::Time& time) override;


private:
    std::shared_ptr<Context> context;

    sf::Sprite wallpaper;
    bool isMenuButtonPressed;

};
