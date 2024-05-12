#include "WindowState.h"


WindowState::WindowState() : isAdded(false), isReplaced(false), remove(false)
{
}


WindowState::~WindowState()
{
}

void WindowState::add(std::unique_ptr<GraphicObject> toAdd, bool replace)
{
    isAdded = true;
    newState = std::move(toAdd);

    isReplaced = replace;
}


void WindowState::popCurrent()
{
    remove = true;
}


void WindowState::processStateChange()
{
    if (remove && (!stateStack.empty()))
    {
        stateStack.pop();

        if (!stateStack.empty())
        {
            stateStack.top()->start();
        }

        remove = false;
    }

    if (isAdded)
    {
        if (isReplaced && (!stateStack.empty()))
        {
            stateStack.pop();
            isReplaced = false;
        }

        if (!stateStack.empty())
        {
            stateStack.top()->pause();
        }

        stateStack.push(std::move(newState));
        stateStack.top()->init();
        stateStack.top()->start();
        isAdded = false;
    }
}


std::unique_ptr<GraphicObject>& WindowState::getCurrent()
{
    return stateStack.top();
}