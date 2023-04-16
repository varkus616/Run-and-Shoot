#include "Label.h"
#include <ResourceIdentifiers.h>
#include <AssetManager.h>
Label::Label(const std::string& text,Widget* parent) : Widget(parent)
{
    setFont(AssetManager::getFont(Fonts::ID::BASIC));
    setText(text);
    setTextColor(sf::Color(180,93,23));
}

Label::~Label()
{
}
void Label::setFont(const sf::Font& font)
{
    _text.setFont(font);
    updateShape();
}
void Label::setText(const std::string& text)
{
    _text.setString(text);
    updateShape();
}

void Label::setCharacterSize(unsigned int size)
{
    _text.setCharacterSize(size);
    updateShape();
}

unsigned int Label::getCharacterSize()const
{
    return _text.getCharacterSize();
}

void Label::setTextColor(const sf::Color& color)
{
    _text.setColor(color);
}

sf::Vector2f Label::getSize()const
{
    sf::FloatRect rect = _text.getGlobalBounds();
    return sf::Vector2f(rect.width,rect.height);
}

void Label::draw(sf::RenderTarget& target,
                 sf::RenderStates states) const
{
    states.transform.translate(_position);
    target.draw(_text,states);
}

