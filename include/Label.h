#ifndef LABEL_H
#define LABEL_H

#include <Widget.h>

class Label : public Widget
{
    public:
        Label(const Label&) = delete;
        Label& operator=(const Label&) = delete;

        Label(const std::string& text,Widget* parent=nullptr);

        virtual ~Label();

        void setText(const std::string& text);
        void setFont(const sf::Font& font);
        void setCharacterSize(unsigned int size);
        unsigned int getCharacterSize()const;
        void setTextColor(const sf::Color& color);

        virtual sf::Vector2f getSize()const override;

    private:
        sf::Text _text;

        virtual void draw(sf::RenderTarget& target,
                          sf::RenderStates states) const override;
};


#endif // LABEL_H
