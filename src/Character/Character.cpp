#pragma once

#include "Character.hpp"
using namespace Characters;

Character::Character(Type type, Vector2f position, Vector2f hitbox, int hp):
    Entity(type, position, hitbox),
    hp(hp)
    {}

Character::~Character(){}

const int Character::getHP() const {return hp;}

void Character::getDamage(int dmg){
    hp -= dmg;
}

