#include "Graphics/Button.hpp"
#include "Type.hpp"

using namespace Graphics;

Button::Button(sf::Vector2f position):
Ent(Type::Button, position, {BUTTON_SIZE_X, BUTTON_SIZE_Y})
{
    content.setPosition(position);
    content.setFontSize(BUTTON_FONT_SIZE);
    content.setColor(BUTTON_FONT_COLOR);

    initializeSprite();
}

Button::~Button(){}

void Button::initializeSprite(){
    //TODO
    animator->update(position);
}

std::string Button::getContent(){
    return content.getValue();
}

void Button::setContent(std::string content){
    this->content.setValue(content);
}

void Button::update(float dt){
    if(selected){
        //Mudar textura para selecionado
        content.setFontSize(24);
    }else{
        content.setFontSize(BUTTON_FONT_SIZE);
    }    
}

void Button::render(){
    animator->update(position);
    animator->render();
}