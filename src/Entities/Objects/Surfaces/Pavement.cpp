#include "Entities/Objects/Surfaces/Pavement.hpp"

using namespace Entities::Objects::Surfaces;

Pavement::Pavement(sf::Vector2f position):
    Object(Type::Pavement, position, {PLATFORM_WIDTH, PLATFORM_HEIGHT})
{
    initializeSprite();
}

Pavement::~Pavement(){}

void Pavement::update(float dt){
    animator->update(position);
}

void Pavement::initializeSprite(){
    animator->getRectangleShape()->setFillColor(sf::Color::Cyan);
}

void Pavement::save(){}