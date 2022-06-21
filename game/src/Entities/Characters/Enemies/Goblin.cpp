#include "Entities/Characters/Enemies/Goblin.hpp"
#include <iostream>
using namespace Entities::Characters::Enemies;

const float Goblin::goblinAtkTime(1.6);

Goblin::Goblin(sf::Vector2f pos, Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Goblin, pos, sf::Vector2f(GOBLIN_WIDTH, GOBLIN_HEIGHT), GOBLIN_HP, GOBLIN_DMG, p1, p2)
{
    initializeSprite();
    setFacingLeft(true);
}

Goblin::~Goblin(){}

void Goblin::initializeSprite(){
    animator.initializeTexture(GOBLIN_DIR, sf::Vector2u(8, 4));
}

void Goblin::render(){
    animator.update(position);
    //update()
    animator.render();
}

void Goblin::update(float dt){

    if(hp<=0){
        setIsShowing(false);
        return;
    }

    //Atualização Gravidade vetor Y
    speed = sf::Vector2f(speed.x, speed.y + GRAVITY * dt);

    //Limitador de velocidade de queda
    if(speed.y > MAX_SPEED_Y)
        speed = sf::Vector2f(speed.x, MAX_SPEED_Y);

    move({speed.x * dt, speed.y * dt});

    movementGoblin();
    
    //Attack
    if(isAttacking && timeFromAtk<=0.56){ //Tempo da animacao difere do tempo do CD de ataque
        timeFromAtk += dt;
        speed.x = 0;
        animator.update(position, (int) EnemySprite::Attack, 8, dt, getFacingLeft(), 0.07);
    
    //Run
    }else if(abs(speed.x)>0.f){
        animator.update(position, (int) EnemySprite::Run, 8, dt, getFacingLeft(), 0.2);

    //Idle
    }else{
        animator.update(position, (int) EnemySprite::Idle, 4, dt, getFacingLeft(), 0.3);
    }

    atkCD += dt;
    
    if(atkCD >= goblinAtkTime && abs(getNearestPlayer()->getPosition().x - position.x) <= GOBLIN_ATK_RANGE && abs(getNearestPlayer()->getPosition().y - position.y) <= ATK_RANGE_Y){
        //std::cout << "TRYATTACK" << std::endl;
        tryAttack(GOBLIN_DMG);
    }//else if(atkCD < goblinAtkTime)
        
}
    //timeFromAtk+=dt;

void Goblin::movementGoblin(){
    float deltaX = getNearestPlayer()->getPosition().x - position.x;
    if(abs(deltaX)<GOBLIN_DX_MAX && abs(deltaX)>GOBLIN_DX_MIN){
        if(deltaX>0){
            setSpeed(sf::Vector2f(GOBLIN_SPEED_X, getSpeed().y));
            setFacingLeft(false);
        }else{
            setSpeed(sf::Vector2f(- GOBLIN_SPEED_X, getSpeed().y));
            setFacingLeft(true);
        }
    }else{
        setSpeed(sf::Vector2f(0.f, getSpeed().y));
    }
}