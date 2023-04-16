#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <Button.h>
#include <Label.h>


class TextButton : public Button
{
    public:
        TextButton(const TextButton&) = delete;
        TextButton& operator=(const TextButton&) = delete;

        TextButton(const std::string& text, Widget* parent=nullptr);

        virtual ~TextButton();

        void setText(const std::string& text);
        void setFont(const sf::Font& font);
        void setCharacterSize(unsigned int size);
        void setTextColor(const sf::Color& color);

        void setFillColor(const sf::Color& color);
        void setOutlineColor(const sf::Color& color);
        void setOutlineThickness(float thickness);

        virtual sf::Vector2f getSize()const override;

    private:
        sf::RectangleShape _shape;
        Label _label;

        void updateShape()override;
        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const override;

        sf::Color _fillColor;
        sf::Color _outlineColor;

        virtual void onMouseEntered()override;
        virtual void onMouseLeft()override;
};


#endif // TEXTBUTTON_H
