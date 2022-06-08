#include "Entities/Objects/Surfaces/Ground.hpp"

using namespace Entities::Objects::Surfaces;

Ground::Ground(sf::Vector2f position):
    Object(Type::Pavement, position, {GROUND_WIDTH, GROUND_HEIGHT})
{
    initializeSprite();
}

Ground::~Ground(){}

void Ground::initializeSprite(){
    animator->getRectangleShape()->setFillColor(sf::Color::Cyan);
    animator->update(position);
}


void Ground::save(){}