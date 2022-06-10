#include "Entities/Objects/Obstacles/Wagon.hpp"
using namespace Entities::Objects::Obstacles;

Wagon::Wagon(sf::Vector2f position):
    Object(Type::Wagon, position, sf::Vector2f(WAGON_WIDTH, WAGON_HEIGHT))
{}

Wagon::~Wagon(){}

void Wagon::initializeSprite(){

}

void Wagon::save(){

}