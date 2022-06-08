#include "Entities/Characters/Character.hpp"
using namespace Entities::Characters;

Character::Character(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg):
    Entity(t, position, size),
    hp(hp),
    damage(dmg),
    isAttacking(false),
    dirX(Direction::Idle),
    dirY(Direction::Idle)
    {}

Character::~Character(){}

const int Character::getHP() const {return hp;}
const int Character::getDamage() const {return damage;}
const bool Character::getIsAttacking() const{return isAttacking;}

void Character::setIsAttacking(bool isAttacking){
    this->isAttacking = isAttacking;
}

void Character::receiveDMG(int dmg){
    hp -= dmg;
}