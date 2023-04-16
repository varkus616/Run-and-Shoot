#ifndef GAMESTATE_H
#define GAMESTATE_H


#include <State.h>
#include <Player.h>
#include <World.h>
#include <SFML/Graphics.hpp>
#include <Enemy.h>


class GameState : public State
{
    public:
        GameState(StateStack& stack, Context context);
        virtual ~GameState();

        void draw() override;
        bool update(sf::Time deltaTime) override;
        bool handleEvent(const sf::Event& event) override;
    private:
        void loadTextures();
        void spawnEnemy(sf::Time deltaTime);
        World             _world;
        sf::RenderWindow& _window;
        Player*           _player;
        sf::Time timeSinceLastSpawn;

};

#endif // GAMESTATE_H
