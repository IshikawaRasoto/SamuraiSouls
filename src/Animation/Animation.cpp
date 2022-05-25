#include "Animation/Animation.hpp"

Animation::Animation(sf::Vector2f size):
    pGM(GraphicsManager::getInstance())
{
    body.setFillColor(sf::Color::Green);
    body.setSize(size);
}

Animation::~Animation(){
    pGM = nullptr;
}

void Animation::update(sf::Vector2f position){
    body.setPosition(position);
    //body.setTextureRect(uvRect);
}

void Animation::setGraphMngr(GraphicsManager* pGraphMngr){
    if(pGraphMngr)
        pGM = pGraphMngr;
}

void Animation::render(){
    pGM->draw(body);
}