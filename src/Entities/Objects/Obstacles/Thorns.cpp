#include "Entities/Objects/Obstacles/Thorns.hpp"
using namespace Entities::Objects;

const int Obstacles::Thorns::dmg(20);

Obstacles::Thorns::Thorns(sf::Vector2f position):
    Object(Type::Thorns, position, sf::Vector2f(THORNS_WIDTH, THORNS_HEIGHT))
{}

Obstacles::Thorns::~Thorns(){}

const int Obstacles::Thorns::getDmg() const{return dmg;}

void Obstacles::Thorns::update(const float dt){}
void Obstacles::Thorns::render(){}
void Obstacles::Thorns::initializeSprite(){}