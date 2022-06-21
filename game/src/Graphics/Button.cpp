#include "Graphics/Button.hpp"
#include "Type.hpp"

using namespace Graphics;

Button::Button(std::string content, sf::Vector2f position, std::string fontDir):
    Ent(Type::Button, position, {BUTTON_SIZE_X, BUTTON_SIZE_Y}),
    content(content, position, fontDir)
{
    this->content.setFontSize(BUTTON_FONT_SIZE);
    this->content.setColor(BUTTON_FONT_COLOR);

    this->content.setTextAlignment(TextAlignment::Center);

    initializeSprite();
    selected = false;
    selectedColor = BUTTON_FONT_SELECTED_COLOR;
    defaultColor = BUTTON_FONT_COLOR;
}

Button::~Button(){}

void Button::initializeSprite(){
    //TODO
    animator.update(position);
}

std::string Button::getContent(){
    return content.getValue();
}

sf::Color Button::getSelectedColor(){
    return selectedColor;
}

sf::Color Button::getDefaultColor(){
    return defaultColor;
}

void Button::setContent(std::string content){
    this->content.setValue(content);
}

void Button::setSelectedColor(sf::Color color){
    selectedColor = color;
}

void Button::setDefaultColor(sf::Color color){
    defaultColor = color;
}

void Button::update(float dt){
    if(selected){
        content.setColor(selectedColor);
    }else{
        content.setColor(defaultColor);
    }    
}

void Button::render(){
    animator.update(position);
    animator.render();
    content.render();
}

void Button::select(bool selected){
    this->selected = selected;
}