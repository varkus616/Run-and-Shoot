#include "GameState.h"
#include <PositionListener.h>
class AssetManager;

GameState::GameState(StateStack& stack, Context context):
    State(stack,context),
    _world(context.window),
    _window(context.window),
    _player(new Player(_world)),
    timeSinceLastSpawn(sf::Time::Zero)
{
    loadTextures();
    _player->setTexture(AssetManager::getTexture(Textures::ID::Player));
    _player->setScale(sf::Vector2f(_player->calculateScale(
                                    sf::Vector2f(50.f,50.f))));
    _player->getSprite().setPosition(200.f,200.f);
    _world.setPlayer(_player);
}

GameState::~GameState()
{
    delete _player;
    //AssetManager::clearFonts();
    AssetManager::clearTextures();
    _world.clear();
}


void GameState::draw()
{
    _window.draw(_world);
}

bool GameState::update(sf::Time deltaTime)
{
    spawnEnemy(deltaTime);
    _world.update(deltaTime);
    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    _player->handleEvents(event);
    return true;
}

void GameState::loadTextures()
{
    AssetManager::loadTexture("player.jpg",Textures::ID::Player);
    AssetManager::loadTexture("enemy.png",Textures::ID::Enemy);
    AssetManager::loadTexture("bullet.png",Textures::ID::Bullet);
}

void GameState::spawnEnemy(sf::Time deltaTime)
{
    sf::Time timePerSpawn = sf::seconds(1.f);
    timeSinceLastSpawn += deltaTime;

    if (timePerSpawn <= timeSinceLastSpawn)
    {
        timeSinceLastSpawn = sf::Time::Zero;

        int r = std::rand() % 2;

        Entity* temp = new Enemy(_world,sf::Vector2f(r * _window.getSize().x,
                    std::rand()%_window.getSize().y ));
        temp->setTexture(AssetManager::getTexture(Textures::ID::Enemy));
        temp->setScale(temp->calculateScale(sf::Vector2f(50.f,50.f)));
        PositionListener* listener = dynamic_cast<PositionListener*> (temp);
        _player->addListener(listener);
        _world.addEntity(temp);
    }
}
