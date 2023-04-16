#include "State.h"
#include <StateStack.h>

State::Context::Context(sf::RenderWindow& window,AssetManager* manager):
    window(window),
    manager(manager)
    {

    }

State::State(StateStack& stack,
             Context context):
                 _context(context),
                 _stack(&stack)
{

}

State::~State()
{

}


void State::requestStackPush(States::ID stateID)
{
    _stack->pushState(stateID);
}

void State::requestStackPop()
{
    _stack->popState();
}

void State::requestStateClear()
{
    _stack->clearStates();
}

State::Context State::getContext()const
{
    return _context;
}
