#include "Entity.h"
#include <iostream>
Entity::Entity(World& world):
    _world(world),
    _speed(0.f,0.f),
    _isAlive(true)
{}

Entity::~Entity(){}

void Entity::setTexture(const sf::Texture& texture)
{
    _sprite.setTexture(texture);
    _sprite.setOrigin(_sprite.getTextureRect().width/2.f,
                      _sprite.getTextureRect().height/2.f);
}
void Entity::draw(sf::RenderTarget& target,
                  sf::RenderStates states)const
{
    target.draw(_sprite,states.blendMode);
}
sf::Vector2f Entity::calculateScale(sf::Vector2f desiredSize)
{
    sf::IntRect s = _sprite.getTextureRect();
    sf::Vector2f scale = _sprite.getScale();
    scale.x = desiredSize.x / s.width;
    scale.y = desiredSize.y / s.height;
    return scale;
}
void Entity::setScale(sf::Vector2f scale)
{
    _sprite.setScale(scale);
    _sprite.setOrigin(_sprite.getTextureRect().width/2.f,
                      _sprite.getTextureRect().height/2.f);
}
sf::Sprite& Entity::getSprite()
{
    return _sprite;
}
sf::Vector2f Entity::getPosition()const
{
    return _sprite.getPosition();
}
float Entity::getDiameterOfCircumsrcibedCircle()
{
    sf::Vector2f rect(this->getRealSize());
    return std::sqrt((rect.x*rect.x) + (rect.y*rect.y));
}
float Entity::calculateDistance(const sf::Vector2f point)
{
    sf::Vector2f spritePos = _sprite.getPosition();
    float xDist = point.x - spritePos.x;
    float yDist = point.y - spritePos.y;

    return std::sqrt((xDist*xDist)+(yDist*yDist));
}
float Entity::calculateDistance(const float x, const float y)
{
    sf::Vector2f spritePos = _sprite.getPosition();
    float xDist = x - spritePos.x;
    float yDist = y - spritePos.y;

    return std::sqrt((xDist*xDist)+(yDist*yDist));
}
sf::Vector2f Entity::getRealSize()
{
    return sf::Vector2f(_sprite.getTexture()->getSize().x * _sprite.getScale().x,
                      _sprite.getTexture()->getSize().y * _sprite.getScale().y);
}

bool Entity::circleTest(Entity* other)
{
   float distance = this->calculateDistance(other->getPosition());
   float thisRadius = this->getDiameterOfCircumsrcibedCircle()/2.f - 10.f;
   float otherRadius = other->getDiameterOfCircumsrcibedCircle()/2.f - 10.f;
   if (distance <= thisRadius+otherRadius)
        return true;
   else return false;
}
