#pragma once

#include "Entities/Characters/Character.hpp"
using namespace Entities::Characters;

Character::Character(Type t, sf::Vector2f position, sf::Vector2f hitbox, int hp):
    Entity(type, position, hitbox),
    hp(hp)
    {}

Character::~Character(){}

const int Character::getHP() const {return hp;}

void Character::getDamage(int dmg){
    hp -= dmg;
}

