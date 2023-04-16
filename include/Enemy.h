#ifndef ENEMY_H
#define ENEMY_H

#include <Entity.h>
#include <PositionListener.h>
#include <Bullet.h>
#include <Player.h>

class Enemy : public Entity, public PositionListener
{
    public:
        Enemy(World& world,
              sf::Vector2f pos);
        void update(sf::Time deltaTime)override;
        bool isCollide(Entity* other)override;
        void listenPosition(sf::Vector2f position)override;
    private:
        sf::Vector2f playerPos;
};

#endif // ENEMY_H

