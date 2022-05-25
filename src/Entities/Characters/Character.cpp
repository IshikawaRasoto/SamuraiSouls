#include "Entities/Characters/Character.hpp"
using namespace Entities::Characters;

Character::Character(Type t, sf::Vector2f position, sf::Vector2f size, int hp):
    Entity(t, position, size),
    hp(hp),
    dirX(Direction::Idle),
    dirY(Direction::Idle)
    {}

Character::~Character(){}

const int Character::getHP() const {return hp;}

void Character::getDamage(int dmg){
    hp -= dmg;
}

