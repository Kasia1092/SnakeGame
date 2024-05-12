#pragma once

#include <stack>
#include <memory>

#include "GraphicObject.h"


    class WindowState
    {
    public:
        WindowState();
        ~WindowState();

        void add(std::unique_ptr<GraphicObject> toAdd, bool replace = false);
        void popCurrent();
        void processStateChange();
        std::unique_ptr<GraphicObject>& getCurrent();

    private:
        std::stack<std::unique_ptr<GraphicObject>> stateStack;
        std::unique_ptr<GraphicObject> newState;

        bool isAdded;
        bool isReplaced;
        bool remove;
    };

