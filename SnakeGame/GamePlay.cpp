#include "GamePlay.h"
#include "GameOver.h"
#include "PauseGame.h"

#include <SFML/Window/Event.hpp>

#include <stdlib.h>
#include <time.h>
#include <iostream>



GamePlay::GamePlay(std::shared_ptr<Context>& context)
    : context(context),
    score(0),
    snakeDirection({ 16.f, 0.f }),
    elapsedTime(sf::Time::Zero),
    isPaused(false)
{
    srand(time(nullptr));
    
}

GamePlay::~GamePlay()
{
}

void GamePlay::init()
{
    context->assets->addTexture(GRASS, "resources/textures/grass.png", true);
    context->assets->addTexture(FOOD1, "resources/textures/foodn1.png");
    context->assets->addTexture(FOOD2, "resources/textures/foodn2.png");
    context->assets->addTexture(FOOD3, "resources/textures/foodn3.png");
    context->assets->addTexture(FOOD4, "resources/textures/foodn4.png");
    context->assets->addTexture(FOOD5, "resources/textures/foodn5.png");
    context->assets->addTexture(FOOD6, "resources/textures/foodn6.png");
    context->assets->addTexture(FOOD7, "resources/textures/foodn7.png");
    context->assets->addTexture(WALL, "resources/textures/wall.png", true);
    context->assets->addTexture(SNAKE, "resources/textures/snake.png");

    grass.setTexture(context->assets->getTexture(GRASS));
    grass.setTextureRect(context->window->getViewport(context->window->getDefaultView()));

    for (auto& wall : walls)
    {
        wall.setTexture(context->assets->getTexture(WALL));
    }

    walls[0].setTextureRect({ 0, 0, (int)context->window->getSize().x, 16 });
    walls[0].setTextureRect({ 0, 0, (int)context->window->getSize().x, 32 });
    walls[1].setTextureRect({ 0, 0, (int)context->window->getSize().x, 16 });
    walls[1].setPosition(0, context->window->getSize().y - 16);

    walls[2].setTextureRect({ 0, 0, 16, (int)context->window->getSize().y });
    walls[3].setTextureRect({ 0, 0, 16, (int)context->window->getSize().y });
    walls[3].setPosition(context->window->getSize().x - 16, 0);

    food.setTexture(context->assets->getTexture(FOOD1));
    food.setPosition(context->window->getSize().x / 2, context->window->getSize().y / 2);

    snake.init(context->assets->getTexture(SNAKE));

    scoreText.setFont(context->assets->getFont(MAIN_FONT));
    scoreText.setString("Score : " + std::to_string(score));
    scoreText.setPosition(4, 0);
    scoreText.setFillColor(sf::Color(253, 255, 226));
    scoreText.setCharacterSize(28);

    fobj.fileIn();
}


void GamePlay::draw()
{
    context->window->clear();
    context->window->draw(grass);

    for (auto& wall : walls)
    {
        context->window->draw(wall);
    }
    context->window->draw(food);
    context->window->draw(snake);
    context->window->draw(scoreText);

    context->window->display();
}

void GamePlay::input()
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
            sf::Vector2f newDirection = snakeDirection;
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                newDirection = { 0.f, -16.f };
                break;
            case sf::Keyboard::Down:
                newDirection = { 0.f, 16.f };
                break;
            case sf::Keyboard::Left:
                newDirection = { -16.f, 0.f };
                break;
            case sf::Keyboard::Right:
                newDirection = { 16.f, 0.f };
                break;
            case sf::Keyboard::Space:
                context->states->add(std::make_unique<PauseGame>(context));
                break;

            default:
                break;
            }

            if (std::abs(snakeDirection.x) != std::abs(newDirection.x) ||
                std::abs(snakeDirection.y) != std::abs(newDirection.y))
            {
                snakeDirection = newDirection;
            }
        }
    }
}

void GamePlay::update(const sf::Time& time)
{
    if (!isPaused)
    {
        elapsedTime += time;

        if (elapsedTime.asSeconds() > 0.1)
        {
            for (auto& wall : walls)
            {
                if (snake.isOn(wall))
                {
                    context->states->add(std::make_unique<GameOver>(context), true);
                    fobj.addScore(score);
                    fobj.fileOut();
                    break;
                }
            }

            if (snake.isOn(food))
            {
                snake.grow(snakeDirection);

                int x = 0, y = 0, z=1;

                int highest_x = context->window->getSize().x - 3 * 16;
                int highest_y = context->window->getSize().y - 4 * 16;

                x = rand() % highest_x + 16;
                y = rand() % highest_y + 32;
                z = rand() % 7 + 2;                

                
                food.setTexture(context->assets->getTexture(z));
                food.setPosition(x, y);
                mut.lock();
                score += 1;
                scoreText.setString("Score : " + std::to_string(score));
                mut.unlock();
            }
            else
            {
                snake.move(snakeDirection);
            }

            if (snake.isSelfIntersecting())
            {
                fobj.addScore(score);
                fobj.fileOut();

                context->states->add(std::make_unique<GameOver>(context), true);
            }

            elapsedTime = sf::Time::Zero;
        }
    }
}

void GamePlay::pause()
{
    isPaused = true;
}

void GamePlay::start()
{
    isPaused = false;
}