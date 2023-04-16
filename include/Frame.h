#ifndef FRAME_H
#define FRAME_H

#include <Container.h>
#include <ActionTarget.h>
#include <ActionMap.h>

class Frame : public Container, protected ActionTarget<int>
{
    public:
        Frame(const Frame&) = delete;
        Frame& operator=(const Frame&) = delete;

        using ActionTarget<int>::FuncType;

        Frame(sf::RenderWindow& window);

        virtual ~Frame();


        void processEvents();
        bool processEvent(const sf::Event& event);

        void bind(int key,const FuncType& callback);
        void unbind(int key);

        void draw();

        virtual sf::Vector2f getSize()const override;

        enum INPUTS : int
        {
            Escape
        };

    private:
        sf::RenderWindow& _window;

        ActionMap<int>  _GUI_INPUTS;

        virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)override;
        virtual void processEvents(const sf::Vector2f& parent_pos)override;
};


#endif // FRAME_H
