#ifndef BUTTON_H
#define BUTTON_H

#include <Widget.h>
#include <functional>


class Button : public Widget
{
    public:
        Button(const Button&) = delete;
        Button& operator=(const Button&) = delete;

        using FuncType = std::function<void(const sf::Event& event,Button& self)>;
        static FuncType defaultFunc;

        Button(Widget* parent=nullptr);
        virtual ~Button();

        FuncType onClick;

    protected:
        virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)override;

        virtual void onMouseEntered();
        virtual void onMouseLeft();

    private:

        enum Status {
            None = 0,
            Hover
        };
        int _status;
};

#endif // BUTTON_H
