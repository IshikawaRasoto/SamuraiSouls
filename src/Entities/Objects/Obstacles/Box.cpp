#include "Entities/Objects/Obstacles/Box.hpp"
using namespace Entities::Objects::Obstacles;

Box::Box(sf::Vector2f position):
    Object(Type::Box, position, sf::Vector2f(BOX_WIDTH, BOX_HEIGHT))
    {
        initializeSprite();
    }

Box::~Box(){}


void Box::initializeSprite(){
    animator->initializeTexture(BOX_DIR, sf::Vector2u(1,1));
    animator->update(position);
}

void Box::save(){
    //TODO
}

void Box::update(float dt){
    if(!getIsShowing())
        return;
    speed.y += GRAVITY * dt;
    move({0, speed.y});
    animator->update(position);
}

void Box::collide(Entities::Entity* other, sf::Vector2f intersect){
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