#include "Graphics/Text.hpp"

using namespace Graphics;

Managers::GraphicsManager* Text::graphicsManager = Managers::GraphicsManager::getInstance();

Text::Text(std::string value, sf::Vector2f position, std::string path){
    this->value = value;
    text.setPosition(position);

    text.setFont(*graphicsManager->getFont(path));
    text.setFillColor(TEXT_COLOR);
    text.setCharacterSize(TEXT_SIZE);
    setValue(value);
}

Text::~Text(){}

sf::Vector2f Text::getPosition(){
    return text.getPosition();
}

unsigned int Text::getFontSize(){
    return text.getCharacterSize();
}

sf::Vector2f Text::getSize(){
    sf::FloatRect textInfo = text.getLocalBounds();

    return sf::Vector2f(textInfo.width, textInfo.height);
}

std::string Text::getValue(){
    return value;
}

void Text::setPosition(sf::Vector2f position){
    text.setPosition(position);
}

void Text::setColor(const unsigned int R, const unsigned int G, const unsigned int B){
    text.setFillColor(sf::Color(R,G,B));
}

void Text::setColor(sf::Color color){
    text.setFillColor(color);
}

void Text::setFontSize(unsigned int size){
    text.setCharacterSize(size);
}

void Text::setTextAlignment(TextAlignment textAlignment){
    sf::Vector2f textSize = getSize();

    if(textAlignment == TextAlignment::Left){
        text.setOrigin(0,0);
    }else if(textAlignment == TextAlignment::Right){
        text.setOrigin(textSize.x, 0);
    }else if(textAlignment == TextAlignment::Center){
        text.setOrigin(textSize.x/2, textSize.y);
    }
}

void Text::setValue(std::string value){
    this->value = value;
    text.setString(value);
    text.setOrigin({getSize().x/2.f, getSize().y/2.f});
}

void Text::render(){
    graphicsManager->draw(text);
}