#pragma once

#include "Ent.hpp"

Ent::Ent():
    animation(nullptr),
    type(Empty)
    {position = sf::Vector2f(0.0, 0.0);}

Ent::Ent(Type type, sf::Vector2f position):
    animation(new Animation()),
    type(type),
    position(position)
{}

Ent::~Ent(){delete(animation);}

const sf::Vector2f Ent::getPosition() const{return position;}
const Type Ent::getType() const{return type;}

void Ent::changePosition(sf::Vector2f position){
    this->position = position;
}
