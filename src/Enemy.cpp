#include "Enemy.h"
const float PI = 3.14159265;

Enemy::Enemy(World& world,
             sf::Vector2f pos):
            Entity(world),
            playerPos(0.f,0.f)
{
    this->_sprite.setPosition(pos);
    _speed = sf::Vector2f(50.f,50.f);
}

void Enemy::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    float distance = this->calculateDistance(playerPos);
    float dX = playerPos.x - _sprite.getPosition().x;
    float dY = playerPos.y - _sprite.getPosition().y;
    sf::Vector2f turn = sf::Vector2f(dX * 1.f/distance,
                         dY * 1.f/distance);
    float rotation = (std::atan2(dY,dX)) * 180.f/PI;
    _sprite.setRotation(rotation);
    _sprite.move(_speed.x * seconds * turn.x,
                 _speed.y * seconds * turn.y);
}

bool Enemy::isCollide(Entity* other)
{
    if (dynamic_cast<Bullet*>(other) != nullptr){
        return this->circleTest(other);
    }
    else
        return false;
}

void Enemy::listenPosition(sf::Vector2f position)
{
    playerPos = position;
}
