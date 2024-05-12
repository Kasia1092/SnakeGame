#include "GameOver.h"
#include "GamePlay.h"
#include "MainMenu.h"

#include <SFML/Window/Event.hpp>

GameOver::GameOver(std::shared_ptr<Context>& context)
    : context(context), 
    isRetryButtonSelected(true), isRetryButtonPressed(false), 
    isMenuButtonSelected(false), isMenuButtonPressed(false), 
    isExitButtonSelected(false), isExitButtonPressed(false)
{
}

GameOver::~GameOver()
{
}

void GameOver::init()
{
    // Title
    gameOverTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameOverTitle.setString("Game Over");
    gameOverTitle.setOrigin(gameOverTitle.getLocalBounds().width / 2,
        gameOverTitle.getLocalBounds().height / 2);
    gameOverTitle.setPosition(context->window->getSize().x / 2 - 100.f,
        context->window->getSize().y / 2 - 150.f);
    gameOverTitle.setFillColor(sf::Color::Red);
    gameOverTitle.setCharacterSize(60);

    // Play Button
    retryButton.setFont(context->assets->getFont(MAIN_FONT));
    retryButton.setString("Retry");
    retryButton.setOrigin(retryButton.getLocalBounds().width / 2,
        retryButton.getLocalBounds().height / 2);
    retryButton.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2 - 25.f);
    retryButton.setCharacterSize(35);

    // Exit Button
    menuButton.setFont(context->assets->getFont(MAIN_FONT));
    menuButton.setString("menu");
    menuButton.setOrigin(menuButton.getLocalBounds().width / 2,
        menuButton.getLocalBounds().height / 2);
    menuButton.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2 + 25.f);
    menuButton.setCharacterSize(35);

    exitButton.setFont(context->assets->getFont(MAIN_FONT));
    exitButton.setString("Exit");
    exitButton.setOrigin(exitButton.getLocalBounds().width / 2,
        exitButton.getLocalBounds().height / 2);
    exitButton.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2 + 75.f);
    exitButton.setCharacterSize(35);

    context->assets->addTexture(OVER, "resources/textures/snakegameover.png");
    gover.setTexture(context->assets->getTexture(OVER));
}

void GameOver::draw()
{
    context->window->draw(gover);
    context->window->draw(gameOverTitle);
    context->window->draw(retryButton);
    context->window->draw(menuButton);
    context->window->draw(exitButton);
    context->window->display();
}

void GameOver::input()
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
            case sf::Keyboard::Up:
            {
                if (isExitButtonSelected)
                {
                    isRetryButtonSelected = false;
                    isMenuButtonSelected = true;
                    isExitButtonSelected = false;
                }

                else if (isMenuButtonSelected)
                {
                    isRetryButtonSelected = true;
                    isMenuButtonSelected = false;
                    isExitButtonSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (isRetryButtonSelected)
                {
                    isRetryButtonSelected = false;
                    isMenuButtonSelected = true;
                    isExitButtonSelected = false;
                }
                else if (isMenuButtonSelected)
                {
                    isRetryButtonSelected = false;
                    isMenuButtonSelected = false;
                    isExitButtonSelected = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                isRetryButtonPressed = false;
                isMenuButtonPressed = false;
                isExitButtonPressed = false;

                if (isRetryButtonSelected)
                {
                    isRetryButtonPressed = true;
                }
                else if (isMenuButtonSelected)
                {
                    isMenuButtonPressed = true;
                }
                else
                {
                    isExitButtonPressed = true;
                }
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

void GameOver::update(const sf::Time& time)
{
    if (isRetryButtonSelected)
    {
        retryButton.setFillColor(sf::Color(27, 33, 32));
        menuButton.setFillColor(sf::Color(253, 255, 226));
        exitButton.setFillColor(sf::Color(253, 255, 226));
    }
    else if (isMenuButtonSelected)
    {
        retryButton.setFillColor(sf::Color(253, 255, 226));
        menuButton.setFillColor(sf::Color(27, 33, 32));
        exitButton.setFillColor(sf::Color(253, 255, 226));
    }
    else if (isExitButtonSelected)
    {
        retryButton.setFillColor(sf::Color(253, 255, 226));
        menuButton.setFillColor(sf::Color(253, 255, 226));
        exitButton.setFillColor(sf::Color(27, 33, 32));
    }


    if (isRetryButtonPressed)
    {
        context->states->add(std::make_unique<GamePlay>(context), true);
    }
    else if (isMenuButtonPressed)
    {
        context->states->add(std::make_unique<MainMenu>(context), true);
    }
    else if (isExitButtonPressed)
    {
        context->window->close();
    }

}

