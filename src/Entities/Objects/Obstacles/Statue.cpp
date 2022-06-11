#include "Entities/Objects/Obstacles/Statue.hpp"

using namespace Entities::Objects::Obstacles;

Statue::Statue(sf::Vector2f position):
    Object(Type::Statue, position, sf::Vector2f(STATUE_WIDTH, STATUE_HEIGHT))
{   
    initializeSprite();
}

Statue::~Statue(){}

void Statue::initializeSprite(){
    animator->initializeTexture(STATUE_DIR, {1,1});
}

void Statue::save(){}

void Statue::update(float dt){}