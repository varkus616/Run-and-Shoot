#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <State.h>
#include <StateStack.h>
#include <SFML/Graphics.hpp>
#include <GUI.h>

class MenuState : public State
{
    public:
        MenuState(StateStack& stack, Context context);
        ~MenuState();

        void draw() override;
        bool update(sf::Time deltaTime) override;
        bool handleEvent(const sf::Event& event) override;

    private:
        void initGUI();
        sf::RenderWindow& _window;
        Frame             _MainMenu;


};

#endif // MENUSTATE_H
