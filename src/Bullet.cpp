#include "Bullet.h"
#include <iostream>
const float PI = 3.14159265;
Bullet::Bullet(World& world,
               sf::Vector2f playerPos,
               sf::Vector2i mousePos):
    Entity(world),
    _mousePos(mousePos)
{

    _speed = sf::Vector2f(500.f,500.f);
    _sprite.setPosition(playerPos);

    float distance = this->calculateDistance(mousePos.x,mousePos.y);
    float dX = mousePos.x - playerPos.x;
    float dY = mousePos.y - playerPos.y;
    _turn = sf::Vector2f(dX * 1.f/distance,
                         dY * 1.f/distance);

    float rotation = (std::atan2(dY,dX)) * 180.f/PI; // We multiply by 180/PI to get angle in degrees

    _sprite.setRotation(rotation);
}

void Bullet::update(sf::Time deltaTime)
{
    float seconds =  deltaTime.asSeconds();
    _sprite.move(seconds * _speed.x * _turn.x,
                 seconds * _speed.y * _turn.y);

}
bool Bullet::isCollide(Entity* other)
{
    if (dynamic_cast<Enemy*>(other) != nullptr){
        return this->circleTest(other);
    }
    else
        return false;
}
