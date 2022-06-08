#include "Entities/Characters/Enemies/Enemy.hpp"

using namespace Entities::Characters::Enemies;

Enemy::Enemy(Type t, sf::Vector2f position, sf::Vector2f size, int hp, int dmg, Characters::Player* p1, Characters::Player* p2):
    Character(t, position, size, hp, dmg),
    pP1(p1),
    pP2(p2),
    atkCD(0.0),
    timeFromAtk(0.0),
    dx(0.0)
{}

Enemy::~Enemy(){
    pP1 = nullptr;
    pP2 = nullptr;
}

Entities::Characters::Player* Enemy::getNearestPlayer(){
    int x1, x2;
    if(!pP2)
        return pP1;
    x1 = abs(pP1->getPosition().x - position.x);
    x2 = abs(pP2->getPosition().x - position.x);
    if(x1<x2)
        return pP1;
    return pP2;
}

void Enemy::tryAttack(const int dmg){
    if((getNearestPlayer()->getPosition().x - position.x) >= 0 && !getFacingLeft())
        getNearestPlayer()->receiveDMG(dmg);
    else if((getNearestPlayer()->getPosition().x - position.x) <= 0 && getFacingLeft())
        getNearestPlayer()->receiveDMG(dmg);
    setIsAttacking(true);
    timeFromAtk = 0.0; //Utilizado na animacao
    atkCD = 0.0;
}

void Enemy::tryAttack(const int dmg, const float timeOfAtk){
    
    if((getNearestPlayer()->getPosition().x - position.x) >= 0 && !getFacingLeft())
        getNearestPlayer()->receiveDMG(dmg);
    else if((getNearestPlayer()->getPosition().x - position.x) <= 0 && getFacingLeft())
        getNearestPlayer()->receiveDMG(dmg);
    setIsAttacking(true);
    timeFromAtk = 0.0; //Utilizado na animacao
    atkCD = 0.0;
}



/*void Enemy::movement(const float spX){

    dx += speed.x;

    if(dx >= MAX_DX){
        setFacingLeft(true);
        speed = {-spX, speed.y};
    }else if(dx <= 0){
        setFacingLeft(false);
        speed = {spX, speed.y};
    }
}*/

void Enemy::collide(Entity* other, sf::Vector2f intersect){
    Type type = other->getType();

    if(type == Type::Box || type == Type::Pavement){
        moveOnCollision(other, intersect);
    };
}