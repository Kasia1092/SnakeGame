
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "MainMenu.h"

Game::Game() : context(std::make_shared<Context>())
{
    context->window->create(sf::VideoMode(736, 448), "WONSZ <3", sf::Style::Close);
    context->states->add(std::make_unique<MainMenu>(context));
}

Game::~Game()
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (context->window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            context->states->processStateChange();
            context->states->getCurrent()->input();
            context->states->getCurrent()->update(TIME_PER_FRAME);
            context->states->getCurrent()->draw();
        }
    }
}