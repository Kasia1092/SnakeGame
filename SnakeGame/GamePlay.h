#pragma once

#include <memory>
#include <array>
#include <mutex>

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "GraphicObject.h"
#include "Snake.h"
#include "File.h"



class GamePlay : public GraphicObject
{
public:
    GamePlay(std::shared_ptr<Context>& context);
    ~GamePlay();

    void init() override;
    void draw() override;
    void input() override;
   
    void update(const sf::Time& time) override;

    void pause() override;
    void start() override;

private:
    std::shared_ptr<Context> context;
    sf::Sprite grass;
    sf::Sprite food;
    std::array<sf::Sprite, 4> walls;
    Snake snake;

    sf::Text scoreText;
    int score;
    std::mutex mut;

    sf::Vector2f snakeDirection;
    sf::Time elapsedTime;

    bool isPaused;

public:
    File fobj;
  

};