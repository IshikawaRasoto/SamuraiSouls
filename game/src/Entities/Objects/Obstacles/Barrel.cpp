#include "Entities/Objects/Obstacles/Barrel.hpp"
using namespace Entities::Objects::Obstacles;

Barrel::Barrel(sf::Vector2f position):
    Object(Type::Barrel, position, sf::Vector2f(BARREL_WIDTH, BARREL_HEIGHT))
{
    initializeSprite();
}

Barrel::~Barrel(){}

void Barrel::initializeSprite(){
    animator.initializeTexture(BARREL_DIR, {1,1});
}
