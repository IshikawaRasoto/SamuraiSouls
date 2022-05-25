#pragma once

#include "Animation/Animation.hpp"

Animation::Animation():
    pGM(GraphicsManager::getInstance())
{}

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