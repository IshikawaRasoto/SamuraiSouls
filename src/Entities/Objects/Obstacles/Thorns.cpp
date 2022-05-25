#pragma once

#include "Entities/Objects/Obstacles/Thorns.hpp"
using namespace Entities::Objects;

Obstacles::Thorns::Thorns(sf::Vector2f position):
    dmg(20),
    Object(Type::Thorns, position, sf::Vector2f(THORNS_WIDTH, THORNS_HEIGHT))
{
    
}

const int Obstacles::Thorns::getDmg() const{return dmg;}