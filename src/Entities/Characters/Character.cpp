#include "Entities/Characters/Character.hpp"
using namespace Entities::Characters;

Character::Character(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg):
    Entity(t, position, size),
    hp(hp),
    damage(dmg),
    dirX(Direction::Idle),
    dirY(Direction::Idle)
    {}

Character::~Character(){}

const int Character::getHP() const {return hp;}

const int Character::getDMG() const {return damage;}

void Character::receiveDMG(int dmg){
    hp -= dmg;
}