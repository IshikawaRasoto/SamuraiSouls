#include "Entities/Objects/Surfaces/Ground.hpp"

using namespace Entities::Objects::Surfaces;

Ground::Ground(sf::Vector2f position):
    Object(Type::Pavement, position, {PLATFORM_WIDTH, PLATFORM_HEIGHT})
{
    initializeSprite();
}

Ground::~Ground(){}

void Ground::update(float dt){
    animator->update(position);
}

void Ground::initializeSprite(){
    animator->getRectangleShape()->setFillColor(sf::Color::Cyan);
}

void Ground::save(){}