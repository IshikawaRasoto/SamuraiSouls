#include "Animation/Animator.hpp"

Animator::Animator(sf::Vector2f size):
    pGM(GraphicsManager::getInstance())
{
    body.setSize(size);
    body.setOrigin(size.x/2, size.y/2);
}

Animator::~Animator(){
    pGM = nullptr;
}

void Animator::update(sf::Vector2f position){
    body.setPosition(position);
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