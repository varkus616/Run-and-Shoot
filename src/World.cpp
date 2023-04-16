#include "World.h"
#include <Player.h>
World::World(sf::RenderWindow& window):
    _window(window),
    _player(nullptr)
{}

World::~World(){this->clear();}

void World::setPlayer(Player* player)
{
    _player = player;
}

void World::addEntity(Entity* entity)
{
    _entities.push_back(entity);
}

void World::removeEntity(Entity* entity)
{
    auto found = std::find(_entities.begin(),
                           _entities.end(),entity);
    if (found != _entities.end()){
        delete *found;
        _entities.erase(found);
    }
}

void World::update(sf::Time deltaTime)
{
    float width = _window.getSize().x;
    float height = _window.getSize().y;
    _player->update(deltaTime);
    for (auto iter = _entities.begin();iter != _entities.end();iter++)
    {
        (*iter)->update(deltaTime);
        sf::Vector2f pos = (*iter)->getPosition();
        if (pos.x < 0 || pos.x > width ||
            pos.y < 0 || pos.y > height)
                iter = _entities.erase(iter);
    }
    checkCollisions();
}
void World::checkCollisions()
{
    for (auto iter = _entities.begin();iter != _entities.end();iter++){
        for (auto jter = _entities.begin();jter != _entities.end();jter++){
            if ((*iter)->isCollide(*jter) && iter != jter){
                (*iter)->_isAlive = false;
                (*jter)->_isAlive = false;
            }
        }
            if (_player->isCollide(*iter))
                _player->_isAlive = false;
    }
    _entities.remove_if([](const Entity* temp){return !temp->_isAlive;});
}
void World::clear()
{
    for (auto& entity:_entities)
        delete entity;
    _entities.clear();
    delete _player;
}

void World::draw(sf::RenderTarget& target,
                 sf::RenderStates states)const
{
    target.draw(*_player);
    for (auto& entity:_entities)
        target.draw(*entity,states);
}

sf::RenderWindow& World::getWindow()
{
    return _window;
}
