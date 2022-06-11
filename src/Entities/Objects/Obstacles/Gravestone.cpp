#include "Entities/Objects/Obstacles/Gravestone.hpp"
using namespace Entities::Objects::Obstacles;

Gravestone::Gravestone(sf::Vector2f position):
    Object(Type::Gravestone, position, sf::Vector2f(GRAVESTONE_WIDTH, GRAVESTONE_HEIGHT))
{
    initializeSprite();
}

Gravestone::~Gravestone(){}

void Gravestone::initializeSprite(){
    animator->initializeTexture(GRAVESTONE_DIR, sf::Vector2u(1, 1));
    animator->update(position);
}

void Gravestone::save(){}

void Gravestone::update(float dt){
    if(!getIsShowing())
        return;
    speed.y += GRAVITY * dt;
    move({0, speed.y});
    animator->update(position);
}

void Gravestone::collide(Entities::Entity* other, sf::Vector2f intersect){
    Type t = other->getType();
    switch(t){
        case Type::Ground:
            moveOnCollision(other, intersect);
            break;
        case Type::MiniGround:
            moveOnCollision(other, intersect);
            break;
    }
}