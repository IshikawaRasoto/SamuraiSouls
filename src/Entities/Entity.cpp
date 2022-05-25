#include "Entities/Entity.hpp"

using namespace Entities;

Entity::Entity()
{
    size = sf::Vector2f(0.0, 0.0);
    speed = sf::Vector2f(0.0, 0.0);
    showing = false;
}

Entity::Entity(Type t, sf::Vector2f position, sf::Vector2f size):
    Ent(t , position, size)
{
    speed = sf::Vector2f(0.0, 0.0);
    showing = true;
}

Entity::~Entity(){}

const sf::Vector2f Entity::getSpeed() const {return speed;}
const bool Entity::getIsShowing() const {return showing;}

void Entity::setSpeed(const sf::Vector2f speed){
    this->speed = speed;
}

void Entity::setIsShowing(const bool showing){
    this->showing = showing;
}

void Entity::collide(Entity *other, sf::Vector2f intersect){}