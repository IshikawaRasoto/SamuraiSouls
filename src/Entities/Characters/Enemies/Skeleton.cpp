#include "Entities/Characters/Enemies/Skeleton.hpp"
using namespace Entities::Characters::Enemies;

const float Skeleton::attackTime(0.4);

Skeleton::Skeleton(sf::Vector2f pos, Players::Player* p1, Players::Player* p2):
    Enemy(Type::Skeleton, pos, sf::Vector2f(SKELETON_WIDTH, SKELETON_HEIGHT), SKELETON_HP, SKELETON_DMG, p1, p2)
{}

Skeleton::~Skeleton(){}

void Skeleton::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Magenta);
}

void Skeleton::render(){
    animator->render();
}

void Skeleton::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    animator->update(position);
}