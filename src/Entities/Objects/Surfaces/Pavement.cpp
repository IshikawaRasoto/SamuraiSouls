#include "Entities/Objects/Surfaces/Pavement.hpp"

using namespace Entities::Objects::Surfaces;

Pavement::Pavement(sf::Vector2f position):
    Object(Type::Pavement, position, {PAVEMENT_WIDTH, PAVEMENT_HEIGHT})
{
    initializeSprite();
}

Pavement::~Pavement(){}

void Pavement::initializeSprite(){
    animator.initializeTexture(PAVEMENT_DIR, sf::Vector2u(1,1));
    animator.update(position);
}

void Pavement::save(){}

void Pavement::update(const float dt){}