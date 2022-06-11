#include "Entities/Objects/Obstacles/Wagon.hpp"
using namespace Entities::Objects::Obstacles;

Wagon::Wagon(sf::Vector2f position):
    Object(Type::Wagon, position, sf::Vector2f(WAGON_WIDTH, WAGON_HEIGHT))
{
    initializeSprite();
}

Wagon::~Wagon(){}

void Wagon::initializeSprite(){
    animator->initializeTexture(WAGON_DIR, {1,1});
}

void Wagon::save(){

}