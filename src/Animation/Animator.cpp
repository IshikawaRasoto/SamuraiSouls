#include "Animation/Animator.hpp"

GraphicsManager *Animator::pGM = GraphicsManager::getInstance();
//const float Animator::switchTime(0.3);

Animator::Animator(sf::Vector2f size):
    imgCount(sf::Vector2u(0,0)),
    texture(nullptr),
    currentImg(sf::Vector2u(0, 0)),
    deltaTime(0.f)

{
    body.setSize(size);
    body.setOrigin(size.x/2.f, size.y/2.f);
}

Animator::~Animator(){
    // std::cout << texture->getSize().x << "\n";
}

//nao esquecer de colocar as ROles depois
void Animator::update(sf::Vector2f position){

    //uvRect.top =  0 PROBLEMA COM AS SPRITES
    body.setPosition(position);
    body.setTextureRect(uvRect);
}

//TODO
void Animator::update(sf::Vector2f position, int row, int qnt_img_x, float dt, bool facingLeft, float switchTime){

   // std::cout << "Row: " << row << std::endl;

    if(currentImg.y != row)
        currentImg.x = 0;
    currentImg.y = row;

    deltaTime += dt;

    if(deltaTime >= switchTime){
        deltaTime -= switchTime;
        currentImg.x++;
        if(currentImg.x >= qnt_img_x-1)
            currentImg.x = 0;
    }

    uvRect.top = currentImg.y * uvRect.height;

    if(!facingLeft){
        uvRect.left = currentImg.x* abs(uvRect.width);
        uvRect.width = abs(uvRect.width);
    }else{
        uvRect.left = (currentImg.x+1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }

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

    if(texture == nullptr){
        std::cout << "ERROR: Failed to load texture in Animator::initializeTexture" << std::endl;
        exit(1);
    }

    uvRect.width  = texture->getSize().x / float(imgCount.x);
    uvRect.height = texture->getSize().y / float(imgCount.y);

    body.setSize(sf::Vector2f(uvRect.width, uvRect.height));
    body.setOrigin(sf::Vector2f(uvRect.width, uvRect.height) / 2.f);
    body.setTexture(texture);
}