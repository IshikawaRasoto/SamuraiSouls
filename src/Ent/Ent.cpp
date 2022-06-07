#include "Ent/Ent.hpp"

Ent::Ent():
    animator(nullptr),
    t(Empty)
{
    position = sf::Vector2f(0.0f, 0.0f);
    size = sf::Vector2f(0.0f, 0.0f);
}

Ent::Ent(Type t, sf::Vector2f position, sf::Vector2f size):
    animator(new Animator(size)),
    t(t),
    position(position),
    size(size)
{}

Ent::~Ent(){delete(animator);}

const sf::Vector2f Ent::getPosition() const{return position;}
const Type Ent::getType() const{return t;}
const sf::Vector2f Ent::getSize() const {return size;}

void Ent::setPosition(sf::Vector2f position){
    this->position = position;
}

void Ent::moveBody(const sf::Vector2f v){
    position = sf::Vector2f(position.x + v.x, position.y + v.y);
}

void Ent::render(){
    animator->update(position);
    animator->render();
}

void Ent::update(const float dt){}