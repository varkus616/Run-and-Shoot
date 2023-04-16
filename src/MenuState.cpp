#include "MenuState.h"
#include <iostream>

MenuState::MenuState(StateStack& stack, Context context):
    State(stack,context),
    _window(context.window),
    _MainMenu(_window)
{
    initGUI();

}

MenuState::~MenuState()
{}

void MenuState::draw()
{
    _window.draw(_MainMenu);
}

bool MenuState::update(sf::Time deltaTime)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    _MainMenu.processEvent(event);
    _MainMenu.processEvents();
    return true;
}

void MenuState::initGUI()
{
    VLayout* layout = new VLayout();
    layout->setSpace(25);

    Label*      TitleHeader = new Label("Run and Shoot");
    TextButton* PlayButton = new TextButton("New Game");
    PlayButton->onClick = [this](const sf::Event&,Button& button)
    {
      requestStateClear();
      requestStackPush(States::ID::GameState);
    };
    TextButton* OptionsButton = new TextButton("Options");
    OptionsButton->onClick = [this](const sf::Event&,Button& button)
    {
        std::cout<<"TEST"<<std::endl;
    };
    TextButton* ExitButton = new TextButton("Exit");
    ExitButton->onClick = [this](const sf::Event&,Button& button)
    {
      _window.close();
    };

    layout->add(TitleHeader);
    layout->add(PlayButton);
    layout->add(OptionsButton);
    layout->add(ExitButton);

    _MainMenu.setLayout(layout);
    _MainMenu.bind(_MainMenu.INPUTS::Escape,
                   [this](const sf::Event& event)
    {
         this->_window.close();
    });


}
