#include "Entities/Characters/Enemies/Enemy.hpp"

using namespace Entities::Characters::Enemies;

Enemy::Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Players::Player* p1 = nullptr, Players::Player* p2 = nullptr):
    Character(t, position, size, hp, dmg),
    pP1(p1),
    pP2(p2),
    atkCD(0.0),
    timeFromAtk(0.0)
{}

Enemy::~Enemy(){
    pP1 = nullptr;
    pP2 = nullptr;
}

const Player* Enemy::getNearestPlayer() const{
    int x1, x2;
    if(!pP2)
        return pP1;
    x1 = abs(pP1->getPosition().x - position.x);
    x2 = abs(pP2->getPosition().x - position.x);
    if(x1<x2)
        return pP1;
    return pP2;
}