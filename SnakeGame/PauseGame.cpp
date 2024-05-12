#include "PauseGame.h"

#include <SFML/Window/Event.hpp>

PauseGame::PauseGame(std::shared_ptr<Context>& context)
    : context(context)
{
}

PauseGame::~PauseGame()
{
}

void PauseGame::init()
{
    // Title
    pauseTitle.setFont(context->assets->getFont(MAIN_FONT));
    pauseTitle.setString("Pause");
    pauseTitle.setOrigin(pauseTitle.getLocalBounds().width / 2,
        pauseTitle.getLocalBounds().height / 2);
    pauseTitle.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2);
    pauseTitle.setCharacterSize(28);
    pauseTitle.setFillColor(sf::Color::Black);
}

void PauseGame::draw()
{
    context->window->draw(pauseTitle);
    context->window->display();
}

void PauseGame::input()
{
    sf::Event event;
    while (context->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Space:
            {
                context->states->popCurrent();
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void PauseGame::update(const sf::Time& time)
{
}

