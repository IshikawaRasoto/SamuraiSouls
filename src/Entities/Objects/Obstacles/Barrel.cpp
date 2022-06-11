#include "Entities/Objects/Obstacles/Barrel.hpp"
using namespace Entities::Objects::Obstacles;

Barrel::Barrel(sf::Vector2f position):
    Object(Type::Barrel, position, sf::Vector2f(BARREL_WIDTH, BARREL_HEIGHT))
{
    initializeSprite();
}

Barrel::~Barrel(){}

void Barrel::initializeSprite(){
    animator->initializeTexture(BARREL_DIR, {1,1});
}

void Barrel::save(){
    //TODO
}

void Barrel::update(float dt){
    if(!getIsShowing())
        return;
    speed = sf::Vector2f(0, speed.y + GRAVITY * dt);
    move({speed.x * dt, speed.y * dt});
    animator->update(position);
}

void Barrel::collide(Entities::Entity* other, sf::Vector2f intersect){
    Type t = other->getType();
    switch(t){
        case Type::Pavement:
            moveOnCollision(other, intersect);
            break;
        case Type::Ground:
            moveOnCollision(other, intersect);
            break;
        case Type::MiniGround:
            moveOnCollision(other, intersect);
            break;
        case Type::Box:
            moveOnCollision(other, intersect);
            break;
    }
}
