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
const bool Entity::getFacingLeft() const {return facingLeft;}

void Entity::setSpeed(const sf::Vector2f speed){
    this->speed = speed;
}

void Entity::setFacingLeft(const bool facingLeft){
    this->facingLeft = facingLeft;
}

void Entity::move(sf::Vector2f v){
    moveBody(v);
}

void Entity::collide(Entity *other, sf::Vector2f intersect){
    Type type = other->getType();

    switch (type){
        case Type::Pavement:
            moveOnCollision(other, intersect);
            break;
        case Type::Box:
            moveOnCollision(other, intersect);
            break;
        case Type::Barrel:
            moveOnCollision(other, intersect);
            break;
        case Type::InvisibleBlock:
            moveOnCollision(other, intersect);
            break;
        case Type::ThornsBase:
            moveOnCollision(other, intersect);
            break;
        case Type::Ground:
            moveOnCollision(other, intersect);
            break;
        case Type::Player:
            moveOnCollision(other, intersect);
            break;
    }
}

void Entity::moveOnCollision(Entity *other, sf::Vector2f intersect){
    if(intersect.x > intersect.y){
        if(other->getPosition().x < position.x){
            position.x -= intersect.x;
        }else{
            position.x += intersect.x;
        }
        
        speed.x = 0.0f;
    }else{
        if(other->getPosition().y < position.y){
            position.y -= intersect.y;
        }else{
            position.y += intersect.y;
        }
        speed.y = 0.0f;
    }
}

void Entity::update(const float dt){
    speed.y += GRAVITY * dt;
    move({speed.x * dt, speed.y * dt});
}