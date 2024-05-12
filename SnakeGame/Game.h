#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Textures.h"
#include "WindowState.h"

enum AssetID
{
    MAIN_FONT = 0,
    GRASS,
    FOOD1,
    FOOD2,
    FOOD3,
    FOOD4,
    FOOD5,
    FOOD6,
    FOOD7,
    WALL,
    SNAKE,
    MENU,
    OVER,
    INSTRUCT,
    LEADER
};

struct Context
{
   
    std::unique_ptr<Textures> assets;
    std::unique_ptr<WindowState> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context()
    {
        
        assets = std::make_unique<Textures>();
        states = std::make_unique<WindowState>();
        window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    std::shared_ptr<Context> context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
};
