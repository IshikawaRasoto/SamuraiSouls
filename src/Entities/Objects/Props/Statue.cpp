#include "Entities/Objects/Props/Statue.hpp"
using namespace Entities::Objects::Props;

Statue::Statue(sf::Vector2f position):
    Object(Type::Statue, position, sf::Vector2f(STATUE_WIDTH, STATUE_HEIGHT))
{
    initializeSprite();
}

Statue::~Statue(){}

void Statue::initializeSprite(){
    animator.initializeTexture(STATUE_DIR, {1, 1});
}

void Statue::save(){
    //TODO
}

void Statue::update(float dt){}