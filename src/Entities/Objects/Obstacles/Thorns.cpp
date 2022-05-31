#include "Entities/Objects/Obstacles/Thorns.hpp"
using namespace Entities::Objects::Obstacles;

const int Thorns::dmg(20);

Thorns::Thorns(sf::Vector2f position):
    Object(Type::Thorns, position, sf::Vector2f(THORNS_WIDTH, THORNS_HEIGHT))
{}

Thorns::~Thorns(){}

const int Thorns::getDmg() const{return dmg;}

void Thorns::update(const float dt){}
void Thorns::render(){}
void Thorns::initializeSprite(){}

void Thorns::save(){
    //TODO
}