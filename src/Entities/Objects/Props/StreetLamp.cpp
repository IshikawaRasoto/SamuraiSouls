#include "Entities/Objects/Props/StreetLamp.hpp"
using namespace Entities::Objects::Props;

StreetLamp::StreetLamp(sf::Vector2f position):
    Object(Type::StreetLamp, position, sf::Vector2f(STREET_LAMP_WIDTH, STREET_LAMP_HEIGHT))
{
    initializeSprite();
}

StreetLamp::~StreetLamp(){}

void StreetLamp::initializeSprite(){
    animator.initializeTexture(STREET_LAMP_DIR, {1, 1});
}

void StreetLamp::save(){
    //TODO
}

void StreetLamp::update(float dt){}