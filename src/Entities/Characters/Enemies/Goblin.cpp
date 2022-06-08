#include "Entities/Characters/Enemies/Goblin.hpp"
#include <iostream>
using namespace Entities::Characters::Enemies;

const float Goblin::goblinAtkTime(0.4);

Goblin::Goblin(sf::Vector2f pos, Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Goblin, pos, sf::Vector2f(GOBLIN_WIDTH, GOBLIN_HEIGHT), GOBLIN_HP, GOBLIN_DMG, p1, p2)
{
    initializeSprite();
}

Goblin::~Goblin(){}

void Goblin::initializeSprite(){
    animator->initializeTexture(GOBLIN_DIR, sf::Vector2u(8, 4));
}

void Goblin::render(){
    animator->update(position);
    animator->render();
}

void Goblin::update(float dt){
    if(hp<0){
        setIsShowing(false);
        return;
    }

    movement(GOBLIN_SPEED_X);

    speed = sf::Vector2f(speed.x, speed.y + GRAVITY * dt);

    if(speed.y > MAX_SPEED_Y)
        speed = sf::Vector2f(speed.x, MAX_SPEED_Y);

    atkCD += dt;
    timeFromAtk+=dt;
    if((atkCD >= goblinAtkTime) && (abs(getNearestPlayer()->getPosition().x - position.x) <= ATK_RANGE))
        attack(GOBLIN_DMG);
    
    move({speed.x * dt, speed.y * dt});

    if(timeFromAtk<=goblinAtkTime){
        speed.x = 0;
        animator->update(position, (int) EnemySprite::Attack, 8, dt, getFacingLeft());
    }else{
        animator->update(position, (int) EnemySprite::Idle, 4, dt, getFacingLeft());
    }
}

void Goblin::save(){
    //TODO
}