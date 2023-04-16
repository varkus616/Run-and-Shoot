#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include <Bullet.h>
#include <list>
#include <PositionListener.h>
#include <Enemy.h>
#include <ActionTarget.h>

class Player : public Entity , protected ActionTarget<int>
{
    public:
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;

        Player(World& world);
        void handleEvents(const sf::Event& event);
        void update(sf::Time deltaTime) override;
        bool isCollide(Entity* other) override;
        void shoot();

        void addListener(PositionListener* listener);
        void removeListener(PositionListener* listener);
    private:
        void updateListeners();
        void initPlayerInputs();
        std::vector<PositionListener*> _positionListeners;

        ActionMap<int> playerInputs;
        enum PlayerInputs : int
        {
            Up,
            UpRel,
            Down,
            DownRel,
            Left,
            LeftRel,
            Right,
            RightRel,
            Shoot
        };

        bool _movingTop;
        bool _movingLeft;
        bool _movingRight;
        bool _movingBot;
};

#endif // PLAYER_H
