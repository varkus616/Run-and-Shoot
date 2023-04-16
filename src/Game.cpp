#include "Game.h"
#include <iostream>
#include <GameState.h>
#include <MenuState.h>
Game::Game():
    _window(sf::VideoMode(400,400),"THE GAME"),
    _manager(AssetManager::getInstance()),
    _stateStack(State::Context(_window,_manager))
{
    AssetManager::loadFont("Roboto-Regular.ttf",Fonts::ID::BASIC);
    _stateStack.registerState<GameState>(States::ID::GameState);
    _stateStack.registerState<MenuState>(States::ID::MenuState);
    _stateStack.pushState(States::ID::MenuState);
    //_stateStack.pushState(States::ID::GameState);
}

void Game::run(float fps=60.f)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f/fps);
    while (_window.isOpen())
    {
        handleInput();
        bool repaint = false;
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            repaint = true;
            update(timePerFrame);
            render();
        }
        if (repaint)
            render();
    }
    _stateStack.clearStates();
}
void Game::handleInput()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            _window.close();
            if (event.key.code == sf::Keyboard::F1){
                _stateStack.clearStates();
                _stateStack.pushState(States::ID::GameState);
            }
        }
        _stateStack.handleEvent(event);
    }
}
void Game::update(sf::Time deltaTime)
{
    _stateStack.update(deltaTime);
}
void Game::render()
{
    _window.clear();

    _stateStack.draw();

    _window.display();
}
