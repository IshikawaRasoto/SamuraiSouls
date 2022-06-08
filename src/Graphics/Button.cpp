#include "Graphics/Button.hpp"
#include "Type.hpp"

using namespace Graphics;

Button::Button(std::string content, sf::Vector2f position):
    Ent(Type::Button, position, {BUTTON_SIZE_X, BUTTON_SIZE_Y})
{
    this->content.setPosition(position);
    this->content.setFontSize(BUTTON_FONT_SIZE);
    this->content.setColor(BUTTON_FONT_COLOR);

    setContent(content);
    initializeSprite();
    selected = false;
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
        content.setColor(sf::Color(100,100,100));
    }else{
        content.setColor(BUTTON_FONT_COLOR);
    }    
}

void Button::render(){
    animator->update(position);
    animator->render();
    content.render();
}

void Button::select(bool selected){
    this->selected = selected;
}