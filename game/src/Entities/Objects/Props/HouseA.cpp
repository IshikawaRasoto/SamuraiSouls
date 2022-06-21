#include "Entities/Objects/Props/HouseA.hpp"
using namespace Entities::Objects::Props;

HouseA::HouseA(sf::Vector2f position):
    Object(Type::HouseA, position, sf::Vector2f(HOUSE_A_WIDTH, HOUSE_A_HEIGHT))
{
    initializeSprite();
}

HouseA::~HouseA(){}

void HouseA::initializeSprite(){
    animator.initializeTexture(HOUSE_A_DIR, {1, 1});
}

void HouseA::update(float dt){}