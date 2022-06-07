#include "Entities/Objects/Obstacles/Barrel.hpp"
using namespace Entities::Objects::Obstacles;

Barrel::Barrel(sf::Vector2f position):
    Object(Type::Barrel, position, sf::Vector2f(BARREL_WIDTH, BARREL_HEIGHT))
{}

Barrel::~Barrel(){}

void Barrel::initializeSprite(){
    sf::RectangleShape* body = animator->getRectangleShape();
}

void Barrel::render(){
    animator->render();
}

void Barrel::update(const float dt){
    animator->update(position);
}