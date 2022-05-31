#include "Animation/Animator.hpp"

Animator::Animator(sf::Vector2f size):
    pGM(GraphicsManager::getInstance())
{
    body.setSize(size);
}

Animator::~Animator(){
    pGM = nullptr;
}

void Animator::update(sf::Vector2f position){
    body.setPosition(position);
    //body.setTextureRect(uvRect);
}

void Animator::setGraphMngr(GraphicsManager* pGraphMngr){
    if(pGraphMngr)
        pGM = pGraphMngr;
}

void Animator::render(){
    pGM->draw(body);
}

sf::RectangleShape* Animator::getRectangleShape(){
    return &body;
}