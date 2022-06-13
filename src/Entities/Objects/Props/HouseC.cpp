#include "Entities/Objects/Props/HouseC.hpp"
using namespace Entities::Objects::Props;

HouseC::HouseC(sf::Vector2f position):
    Object(Type::HouseB, position, sf::Vector2f(HOUSE_C_WIDTH, HOUSE_C_HEIGHT))
{
    initializeSprite();
}

HouseC::~HouseC(){}

void HouseC::initializeSprite(){
    animator.initializeTexture(HOUSE_C_DIR, {1, 1});
}

void HouseC::update(float dt){}