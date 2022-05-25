#pragma once

#include "Ent/Ent.hpp"

Ent::Ent():
    animation(nullptr),
    t(Empty)
{
    position = sf::Vector2f(0.0f, 0.0f);
    size = sf::Vector2f(0.0f, 0.0f);
}

Ent::Ent(Type t, sf::Vector2f position, sf::Vector2f size):
    animation(new Animation(size)),
    t(t),
    position(position),
    size(size)
{}

Ent::~Ent(){delete(animation);}

const sf::Vector2f Ent::getPosition() const{return position;}
const Type Ent::getType() const{return t;}

void Ent::setPosition(sf::Vector2f position){
    this->position = position;
}
