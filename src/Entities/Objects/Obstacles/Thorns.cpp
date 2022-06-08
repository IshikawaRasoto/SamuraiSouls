#include "Entities/Objects/Obstacles/Thorns.hpp"
using namespace Entities::Objects::Obstacles;

Thorns::Thorns(sf::Vector2f position):
    Object(Type::Thorns, position, sf::Vector2f(THORNS_WIDTH, THORNS_HEIGHT))
{}

Thorns::~Thorns(){}

void Thorns::initializeSprite(){}

void Thorns::save(){
    //TODO
}