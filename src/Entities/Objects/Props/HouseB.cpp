#include "Entities/Objects/Props/HouseB.hpp"
using namespace Entities::Objects::Props;

HouseB::HouseB(sf::Vector2f position):
    Object(Type::HouseB, position, sf::Vector2f(HOUSE_B_WIDTH, HOUSE_B_HEIGHT))
{
    initializeSprite();
}

HouseB::~HouseB(){}

void HouseB::initializeSprite(){
    animator.initializeTexture(HOUSE_B_DIR, {1, 1});
}

void HouseB::save(){
    //TODO
}

void HouseB::update(float dt){}