#ifndef POSITIONLISTENER_H
#define POSITIONLISTENER_H


class PositionListener
{
    public:
        virtual void listenPosition(sf::Vector2f position) = 0;
};

#endif // POSITIONLISTENER_H
