#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <list>
#include <Entity.h>

class Entity;
class Player;
class World : public sf::Drawable
{
    public:
        World(sf::RenderWindow& window);
        ~World();
        void addEntity(Entity* entity);
        void setPlayer(Player* player);
        void removeEntity(Entity* entity);
        void update(sf::Time deltaTime);
        void clear();
        sf::RenderWindow& getWindow();

    private:
        void draw(sf::RenderTarget& target,
                  sf::RenderStates states)const override;
        void checkCollisions();
        std::list<Entity*> _entities;
        sf::RenderWindow&  _window;
        Player*            _player;
};

#endif // WORLD_H

