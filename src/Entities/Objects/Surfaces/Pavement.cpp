#include "Entities/Objects/Surfaces/Pavement.hpp"

using namespace Entities::Objects::Surfaces;

Pavement::Pavement(sf::Vector2f position):
    Object(Type::Pavement, position, {PAVEMENT_WIDTH, PAVEMENT_HEIGHT})
{
    initializeSprite();
}

Pavement::~Pavement(){}

void Pavement::update(float dt){
    animator->update(position);
}

void Pavement::initializeSprite(){
    animator->initializeTexture(PAVEMENT_DIR, sf::Vector2u(1,1));;
}

void Pavement::save(){}