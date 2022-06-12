#include "Entities/Objects/Obstacles/Gravestone.hpp"
using namespace Entities::Objects::Obstacles;

Gravestone::Gravestone(sf::Vector2f position):
    Object(Type::Gravestone, position, sf::Vector2f(GRAVESTONE_WIDTH, GRAVESTONE_HEIGHT))
{
    initializeSprite();
}

Gravestone::~Gravestone(){}

void Gravestone::initializeSprite(){
    animator.initializeTexture(GRAVESTONE_DIR, sf::Vector2u(1, 1));
    animator.update(position);
}

void Gravestone::save(){}