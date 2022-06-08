#include "Entities/Characters/Enemies/Skeleton.hpp"
#include <cmath>

using namespace Entities::Characters::Enemies;

const float Skeleton::skeletonAtkTime(0.4);

Skeleton::Skeleton(sf::Vector2f pos, Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Skeleton, pos, sf::Vector2f(SKELETON_WIDTH, SKELETON_HEIGHT), SKELETON_HP, SKELETON_DMG, p1, p2)
{
    initializeSprite();
}

Skeleton::~Skeleton(){}

void Skeleton::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Magenta);
}

void Skeleton::render(){
    animator->render();
}

void Skeleton::update(float dt){
    if(hp<0){
        setIsShowing(false);
        return;
    }

    //movement(SKELETON_SPEED_X);

    speed = sf::Vector2f(speed.x, speed.y + GRAVITY * dt);

    if(speed.y > MAX_SPEED_Y)
        speed = sf::Vector2f(speed.x, MAX_SPEED_Y);

    atkCD += dt;
    if((atkCD >= skeletonAtkTime) && (abs(getNearestPlayer()->getPosition().x - position.x) <= ATK_RANGE))
            tryAttack(SKELETON_DMG);
    

    move({speed.x * dt, speed.y * dt});

    animator->update(position);
}

void Skeleton::save(){
    //TODO
}