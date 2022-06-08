#include "Entities/Characters/Enemies/Minion.hpp"
using namespace Entities::Characters::Enemies;

const float Minion::minionAtkTime(0.4);

Minion::Minion(sf::Vector2f pos, Characters::Player *p1, Characters::Player *p2):
    Enemy(Type::Minion, pos, sf::Vector2f(MINION_WIDTH, MINION_HEIGHT), MINION_HP, MINION_DMG, p1, p2)
{
    initializeSprite();
}

Minion::~Minion(){}

void Minion::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Red);
}

void Minion::render(){
    animator->render();
}

void Minion::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    animator->update(position);
}

void Minion::attack(){
    //TODO
}

void Minion::save(){
    //TODO
}