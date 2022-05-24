#pragma once

#include "Entity/Entity.hpp"

using namespace Entities;

Entity::Entity()
{
    hitbox = sf::Vector2f(0.0, 0.0);
    speed = sf::Vector2f(0.0, 0.0);
    showing = false;
    facingLeft= false;
}

Entity::Entity(Type id, sf::Vector2f position, sf::Vector2f hitbox):
    Ent(id , position)
{
    this->hitbox = hitbox;
    speed = sf::Vector2f(0.0, 0.0);
    showing = true;
    facingLeft = false;
}

Entity::~Entity(){}

const sf::Vector2f Entity::getSpeed() const {return speed;}
const sf::Vector2f Entity::getHitbox() const {return hitbox;}
const bool Entity::getIsShowing() const {return showing;}
const bool Entity::getIsFacingLeft() const {return facingLeft;}

void Entity::setSpeed(const sf::Vector2f speed){
    this->speed = speed;
}

void Entity::setHitbox(const sf::Vector2f hitbox){
    this->hitbox = hitbox;
}

void Entity::setIsShowing(const bool showing){
    this->showing = showing;
}

void Entity::setIsFacingLeft(const bool facingLeft){
    this->facingLeft = facingLeft;
}

