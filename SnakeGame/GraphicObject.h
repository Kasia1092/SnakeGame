#pragma once

#include <SFML/System/Time.hpp>


class GraphicObject
{
public:
    GraphicObject() {};
    ~GraphicObject() {};

    virtual void init() = 0;
    virtual void draw() = 0;
    virtual void input() = 0;
    virtual void update(const sf::Time& time) = 0;
   

    virtual void pause() {};
    virtual void start() {};
};
