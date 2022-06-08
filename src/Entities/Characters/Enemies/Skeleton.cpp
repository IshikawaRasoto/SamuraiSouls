#include "Entities/Characters/Enemies/Skeleton.hpp"
#include <cmath>

using namespace Entities::Characters::Enemies;

const float Skeleton::skeletonAtkTime(1.6);

Skeleton::Skeleton(sf::Vector2f pos, Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Skeleton, pos, sf::Vector2f(SKELETON_WIDTH, SKELETON_HEIGHT), SKELETON_HP, SKELETON_DMG, p1, p2)
{
    initializeSprite();
}

Skeleton::~Skeleton(){}

void Skeleton::initializeSprite(){
    animator->initializeTexture(SKELETON_DIR, sf::Vector2u(8, 4));
}

void Skeleton::render(){
    animator->render();
}

void Skeleton::update(float dt){
    if(hp<=0){
        setIsShowing(false);
        return;
    }

    speed = sf::Vector2f(speed.x, speed.y + GRAVITY * dt);

    if(speed.y > MAX_SPEED_Y)
        speed = sf::Vector2f(speed.x, MAX_SPEED_Y);

    move({speed.x * dt, speed.y * dt});

    movementSkeleton();

    //Attack
    if(isAttacking && timeFromAtk<=0.56){ //Tempo da animacao difere do tempo do CD de ataque
        timeFromAtk += dt;
        speed.x = 0;
        animator->update(position, (int) EnemySprite::Attack, 8, dt, getFacingLeft(), 0.07);
    
    //Run
    }else if(abs(speed.x)>0.f){
        animator->update(position, (int) EnemySprite::Run, 4, dt, getFacingLeft(), 0.2);

    //Idle
    }else{
        animator->update(position, (int) EnemySprite::Idle, 4, dt, getFacingLeft(), 0.3);
    }

    atkCD += dt;
    if((atkCD >= skeletonAtkTime) && (abs(getNearestPlayer()->getPosition().x - position.x) <= SKELETON_ATK_RANGE && abs(getNearestPlayer()->getPosition().y - position.y)) <= ATK_RANGE_Y)
            tryAttack(SKELETON_DMG);
}

void Skeleton::save(){
    //TODO
}

void Skeleton::movementSkeleton(){
    float deltaX = getNearestPlayer()->getPosition().x - position.x;
    if(abs(deltaX)<SKELETON_DX_MAX && abs(deltaX)>SKELETON_DX_MIN){
        if(deltaX>0){
            setSpeed(sf::Vector2f(SKELETON_SPEED_X, getSpeed().y));
            setFacingLeft(false);
        }else{
            setSpeed(sf::Vector2f(- SKELETON_SPEED_X, getSpeed().y));
            setFacingLeft(true);
        }
    }else{
        setSpeed(sf::Vector2f(0.f, getSpeed().y));
    }
}