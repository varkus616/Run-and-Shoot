#include "Player.h"
Player::Player(World& world):
    Entity(world),
    ActionTarget(playerInputs),
    _movingTop(false),
    _movingBot(false),
    _movingLeft(false),
    _movingRight(false)
{
    initPlayerInputs();
    _speed = sf::Vector2f(50.f, 50.f);
    bind(PlayerInputs::Up,[this](const sf::Event&)
         {
             _movingTop = true;
         });
    bind(PlayerInputs::UpRel,[this](const sf::Event&)
         {
             _movingTop = false;
         });
    bind(PlayerInputs::Down,[this](const sf::Event&)
         {
             _movingBot = true;
         });
    bind(PlayerInputs::DownRel,[this](const sf::Event&)
         {
             _movingBot = false;
         });
    bind(PlayerInputs::Left,[this](const sf::Event&)
         {
             _movingLeft = true;
         });
    bind(PlayerInputs::LeftRel,[this](const sf::Event&)
         {
             _movingLeft = false;
         });
    bind(PlayerInputs::Right,[this](const sf::Event&)
         {
             _movingRight = true;
         });
    bind(PlayerInputs::RightRel,[this](const sf::Event&)
         {
             _movingRight = false;
         });
    bind(PlayerInputs::Shoot,[this](const sf::Event&)
         {
            this->shoot();
         });

}
void Player::handleEvents(const sf::Event& event)
{
    ActionTarget::processEvent(event);
    ActionTarget::processEvents();
}
void Player::shoot()
{
    Entity* temp = new Bullet(_world,getPosition(),
                              sf::Mouse::getPosition(_world.getWindow()));
    temp->setTexture(AssetManager::getTexture(Textures::ID::Bullet));
    temp->setScale(temp->calculateScale(sf::Vector2f(50.f,50.f)));
    _world.addEntity(temp);
}
void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    sf::Vector2f pos = _sprite.getPosition();
    sf::Vector2f halfSize = this->getRealSize()/2.f;
    sf::RenderWindow& _window = _world.getWindow();
    if (_movingTop && pos.y - halfSize.y > 0.f )
    {
        _sprite.move(0.f,-_speed.y * seconds);
    }
    if(_movingBot && pos.y + halfSize.y < _window.getSize().y)
    {
        _sprite.move(0.f,_speed.y * seconds);
    }
    if(_movingLeft && pos.x - halfSize.x > 0.f)
    {
        _sprite.move(-_speed.x * seconds,0.f);
    }
    if(_movingRight && pos.x + halfSize.x < _window.getSize().x)
    {
        _sprite.move(_speed.x * seconds,0.f);
    }
        this->updateListeners();
}
bool Player::isCollide(Entity* other)
{
    if (dynamic_cast<Enemy*>(other) != nullptr){
        return this->circleTest(other);
    }
    else
        return false;
}
void Player::addListener(PositionListener* listener)
{
    _positionListeners.push_back(listener);
}
void Player::removeListener(PositionListener* listener)
{
    auto found = std::find(_positionListeners.begin(),
                           _positionListeners.end(),listener);
    if (found != _positionListeners.end())
        _positionListeners.erase(found);
}
void Player::updateListeners()
{
    for (auto& el:_positionListeners)
        el->listenPosition(this->getPosition());
}
void Player::initPlayerInputs()
{
    playerInputs.map(PlayerInputs::Up,Action(sf::Keyboard::W));
    playerInputs.map(PlayerInputs::UpRel,Action(sf::Keyboard::W,Action::Type::Released));
    playerInputs.map(PlayerInputs::Down,Action(sf::Keyboard::S));
    playerInputs.map(PlayerInputs::DownRel,Action(sf::Keyboard::S,Action::Type::Released));
    playerInputs.map(PlayerInputs::Left,Action(sf::Keyboard::A));
    playerInputs.map(PlayerInputs::LeftRel,Action(sf::Keyboard::A,Action::Type::Released));
    playerInputs.map(PlayerInputs::Right,Action(sf::Keyboard::D));
    playerInputs.map(PlayerInputs::RightRel,Action(sf::Keyboard::D,Action::Type::Released));
    playerInputs.map(PlayerInputs::Shoot,Action(sf::Keyboard::Space,Action::Type::Pressed));
}
