#include "Instruction.h"
#include "MainMenu.h"

#include <SFML/Window/Event.hpp>
Instruction::Instruction(std::shared_ptr<Context>& context)
    : context(context)
{
}

Instruction::~Instruction()
{
}

void Instruction::init()
{
    context->assets->addTexture(INSTRUCT, "resources/textures/instruction.png");
    wallpaper.setTexture(context->assets->getTexture(INSTRUCT));
}

void Instruction::draw()
{
    context->window->clear();
    context->window->draw(wallpaper);
    context->window->display();
}

void Instruction::input()
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
            case sf::Keyboard::Return:
            {
                isMenuButtonPressed = true;
            }
            default:
            {
                break;
            }
            }

        }

    }
}

void Instruction::update(const sf::Time& time)
{
    if (isMenuButtonPressed)
    {
        context->states->add(std::make_unique<MainMenu>(context), true);
    }
}

