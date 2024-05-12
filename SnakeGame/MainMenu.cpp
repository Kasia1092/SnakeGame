#include "MainMenu.h"
#include "GamePlay.h"
#include "Instruction.h" 
#include "Leaderboard.h"


#include <SFML/Window/Event.hpp>
#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context>& context)
    : context(context), 
    isPlayButtonSelected(true), isPlayButtonPressed(false), 
    isInstructionButtonSelected(false), isInstructionButtonPressed(false),
    isLeaderboardButtonSelected(false), isLeaderboardButtonPressed(false),
    isExitButtonSelected(false), isExitButtonPressed(false)
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
    context->assets->addFont(MAIN_FONT, "resources/fonts/Snake Chan.ttf");
    
    // Title
    gameTitle.setFont(context->assets->getFont(MAIN_FONT));
    gameTitle.setString("Wonsz");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2,
        gameTitle.getLocalBounds().height / 2);
    gameTitle.setPosition(context->window->getSize().x / 2 - 80.f,
        context->window->getSize().y / 2 - 190.f);
    gameTitle.setCharacterSize(70);
    gameTitle.setFillColor(sf::Color(21, 97, 53));

    gamesecTitle.setFont(context->assets->getFont(MAIN_FONT));
    gamesecTitle.setString("Game");
    gamesecTitle.setOrigin(gamesecTitle.getLocalBounds().width / 2,
        gamesecTitle.getLocalBounds().height / 2);
    gamesecTitle.setPosition(context->window->getSize().x / 2 - 50.f,
        context->window->getSize().y / 2 - 125.f);
    gamesecTitle.setCharacterSize(60);
    gamesecTitle.setFillColor(sf::Color(37, 169, 75));

    // Play Button
    playButton.setFont(context->assets->getFont(MAIN_FONT));
    playButton.setString("Play");
    playButton.setOrigin(playButton.getLocalBounds().width / 2,
        playButton.getLocalBounds().height / 2);
    playButton.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2 - 35.f);
    playButton.setCharacterSize(30);

    // Instruction Button
    instructionButton.setFont(context->assets->getFont(MAIN_FONT));
    instructionButton.setString("Instruction");
    instructionButton.setOrigin(instructionButton.getLocalBounds().width / 2,
        instructionButton.getLocalBounds().height / 2);
    instructionButton.setPosition(context->window->getSize().x / 2 + 25.f,
        context->window->getSize().y / 2 + 10.f);
    instructionButton.setCharacterSize(25);

    // Leaderboard Button
    leaderboardButton.setFont(context->assets->getFont(MAIN_FONT));
    leaderboardButton.setString("Leaderboard");
    leaderboardButton.setOrigin(leaderboardButton.getLocalBounds().width / 2 - 30.f,
        instructionButton.getLocalBounds().height / 2);
    leaderboardButton.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2 + 50.f);
    leaderboardButton.setCharacterSize(25);

    // Exit Button
    exitButton.setFont(context->assets->getFont(MAIN_FONT));
    exitButton.setString("Exit");
    exitButton.setOrigin(exitButton.getLocalBounds().width / 2,
        exitButton.getLocalBounds().height / 2);
    exitButton.setPosition(context->window->getSize().x / 2,
        context->window->getSize().y / 2 + 90.f);
    exitButton.setCharacterSize(30);


    context->assets->addTexture(MENU, "resources/textures/snakemenu.png");
    smenu.setTexture(context->assets->getTexture(MENU));
}

void MainMenu::draw()
{
    context->window->clear();
    context->window->draw(smenu);
    context->window->draw(gameTitle);
    context->window->draw(gamesecTitle);
    context->window->draw(playButton);
    context->window->draw(instructionButton);
    context->window->draw(leaderboardButton);
    context->window->draw(exitButton);
    context->window->display();
}

void MainMenu::input()
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
                if (isInstructionButtonSelected)
                {
                    isPlayButtonSelected = true;
                    isInstructionButtonSelected = false;
                    isLeaderboardButtonSelected = false;
                    isExitButtonSelected = false;
                }
                else if (isLeaderboardButtonSelected)
                {
                    isPlayButtonSelected = false;
                    isInstructionButtonSelected = true;
                    isLeaderboardButtonSelected = false;
                    isExitButtonSelected = false;
                }
                else if (isExitButtonSelected)
                {
                    isPlayButtonSelected = false;
                    isInstructionButtonSelected = false;
                    isLeaderboardButtonSelected = true;
                    isExitButtonSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (isPlayButtonSelected)
                {
                    isPlayButtonSelected = false;
                    isInstructionButtonSelected = true;
                    isLeaderboardButtonSelected = false;
                    isExitButtonSelected = false;
                }
                else if (isInstructionButtonSelected)
                {
                    isPlayButtonSelected = false;
                    isInstructionButtonSelected = false;
                    isLeaderboardButtonSelected = true;
                    isExitButtonSelected = false;
                }
                else if (isLeaderboardButtonSelected)
                {
                    isPlayButtonSelected = false;
                    isInstructionButtonSelected = false;
                    isLeaderboardButtonSelected = false;
                    isExitButtonSelected = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {

                if (isPlayButtonSelected)
                {
                    isPlayButtonPressed = true;
                }
                else if (isInstructionButtonSelected)
                {
                    isInstructionButtonPressed = true;
                }
                else if (isLeaderboardButtonSelected)
                {
                    isLeaderboardButtonPressed = true;
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

void MainMenu::update(const sf::Time& time)
{
    if (isPlayButtonSelected)
    {
        playButton.setFillColor(sf::Color(27,33,32));
        instructionButton.setFillColor(sf::Color(253, 255, 226));
        leaderboardButton.setFillColor(sf::Color(253, 255, 226));
        exitButton.setFillColor(sf::Color(253, 255, 226));
    }
    else if (isInstructionButtonSelected)
    {
        playButton.setFillColor(sf::Color(253, 255, 226));
        instructionButton.setFillColor(sf::Color(27, 33, 32));
        leaderboardButton.setFillColor(sf::Color(253, 255, 226));
        exitButton.setFillColor(sf::Color(253, 255, 226));
    }
    else if (isLeaderboardButtonSelected)
    {
        playButton.setFillColor(sf::Color(253, 255, 226));
        instructionButton.setFillColor(sf::Color(253, 255, 226));
        leaderboardButton.setFillColor(sf::Color(27, 33, 32));
        exitButton.setFillColor(sf::Color(253, 255, 226));
    }
    else
    {
        playButton.setFillColor(sf::Color(253, 255, 226));
        instructionButton.setFillColor(sf::Color(253, 255, 226));
        leaderboardButton.setFillColor(sf::Color(253, 255, 226));
        exitButton.setFillColor(sf::Color(27, 33, 32));
    }


    if (isPlayButtonPressed)
    {
        context->states->add(std::make_unique<GamePlay>(context), true);
    }
    else if (isInstructionButtonPressed)
    {
        context->states->add(std::make_unique<Instruction>(context), true);
    }
    else if (isLeaderboardButtonPressed)
    {
        context->states->add(std::make_unique<Leaderboard>(context), true);
    }
    else if (isExitButtonPressed)
    {
        context->window->close();
    }
}

