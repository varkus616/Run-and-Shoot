#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <World.h>

class World;
class Entity : public sf::Drawable
{
    public:
        Entity(World& world);
        virtual ~Entity();

        void setTexture(const sf::Texture& texture);
        virtual void update(sf::Time deltaTime) = 0;

        sf::Vector2f calculateScale(sf::Vector2f desiredSize);
        void setScale(sf::Vector2f scale);

        virtual bool isCollide(Entity* other) = 0;
        sf::Sprite& getSprite();
        sf::Vector2f getPosition()const;

        float calculateDistance(const sf::Vector2f point);
        float calculateDistance(const float x, const float y);
        float getDiameterOfCircumsrcibedCircle();
        sf::Vector2f getRealSize();
    protected:
        bool circleTest(Entity* other);
        void draw(sf::RenderTarget& target,
                  sf::RenderStates states)const override;

        sf::Sprite                  _sprite;
        sf::Vector2f                _speed;
        public:
        World&                      _world;

    public:
        bool                        _isAlive;
};

#endif // ENTITY_H
