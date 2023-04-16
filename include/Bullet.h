#ifndef BULLET_H
#define BULLET_H

#include <Entity.h>
#include <AssetManager.h>
#include <Enemy.h>


class Bullet : public Entity
{
    public:
        Bullet(World& world,
               sf::Vector2f playerPos,
               sf::Vector2i mousePos);
        void update(sf::Time deltaTime)override;
        bool isCollide(Entity* other)override;
    private:
        sf::Vector2i _mousePos;
        sf::Vector2f _turn;
};

#endif // BULLET_H
