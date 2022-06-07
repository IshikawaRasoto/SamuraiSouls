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

//nao esquecer de colocar as ROles depois
void Animator::update(sf::Vector2f position){

    uvRect.top =  0;
    body.setPosition(position);
    body.setTextureRect(uvRect);
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

void Animator::initializeTexture(std::string path, sf::Vector2u imageCount){
    imgCount = imageCount;
    texture = pGM->getTexture(path);
    if(texture == NULL){
        std::cout << "ERROR: Failed to load texture in Animator::initializeTexture" << std::endl;
        exit(1);
    }

    uvRect.width  = texture->getSize().x / float(imgCount.x);
    uvRect.height = texture->getSize().y / float(imgCount.y);

    body.setSize(sf::Vector2f(uvRect.width, uvRect.height));
    body.setOrigin(sf::Vector2f(uvRect.width, uvRect.height) / 2.f);
    body.setTexture(texture);
}