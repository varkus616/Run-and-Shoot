#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <AssetManager.h>
#include <StateStack.h>



class Game
{
    public:
        Game();
        void run(float fps);

    private:
        void handleInput();
        void update(sf::Time deltaTime);
        void render();

        sf::RenderWindow _window;
        AssetManager*    _manager;
        StateStack       _stateStack;


};

#endif // GAME_H
