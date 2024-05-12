#include "MainMenu.h"
#include "GamePlay.h"
#include "Leaderboard.h"
#include "File.h"

#include <SFML/Window/Event.hpp>



Leaderboard::Leaderboard(std::shared_ptr<Context>& context)
    : context(context), isMenuButtonPressed(false)
{
}

Leaderboard::~Leaderboard()
{

}

void Leaderboard::init()
{

    context->assets->addTexture(LEADER, "resources/textures/leaderboard.png");
    wallpaper.setTexture(context->assets->getTexture(LEADER));

    title.setFont(context->assets->getFont(MAIN_FONT));
    title.setString("Best Scores: ");
    title.setOrigin(title.getLocalBounds().width / 2,
        title.getLocalBounds().height / 2);
    title.setPosition(context->window->getSize().x / 2 - 50.f,
        context->window->getSize().y / 2 - 190.f);
    title.setCharacterSize(40);
    title.setFillColor(sf::Color(21, 97, 53));

    File fobj;
    fobj.fileIn();

    for (int i = 0; i < 10; i++)
    {
        float y = 130.f;
        std::string s = std::to_string(i+1);
        s += ".";
        nr[i].setFont(context->assets->getFont(MAIN_FONT));
        nr[i].setString(s);
        nr[i].setOrigin(nr[i].getLocalBounds().width / 2,
            nr[i].getLocalBounds().height / 2);
        nr[i].setPosition(context->window->getSize().x / 2 - 70.f,
            context->window->getSize().y / 2 - (y - (i * 30)));
        nr[i].setCharacterSize(30);
        nr[i].setFillColor(sf::Color(21, 97, 53));
    }

    
    for (int i = 0; i < 10; i++)
    {
        float y = 130.f;
        b[i].setFont(context->assets->getFont(MAIN_FONT));
        b[i].setString(fobj.vec[i]);
        b[i].setOrigin(b[i].getLocalBounds().width / 2,
            b[i].getLocalBounds().height / 2);
        b[i].setPosition(context->window->getSize().x / 2,
            context->window->getSize().y / 2 - (y - (i * 30)));
        b[i].setCharacterSize(30);
        b[i].setFillColor(sf::Color(253, 255, 226));
    }

   
}

void Leaderboard::draw()
{
    context->window->clear();
    context->window->draw(wallpaper);
    context->window->draw(title);
    for (int i = 0; i < 10; i++) {
        context->window->draw(nr[i]);
    }
    for (int i = 0; i < 10; i++) {
       context->window->draw(b[i]);
    }   
    context->window->display();
}

void Leaderboard::input()
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


void Leaderboard::update(const sf::Time& time)
{
    if (isMenuButtonPressed)
    {
        context->states->add(std::make_unique<MainMenu>(context), true);
    }
}

