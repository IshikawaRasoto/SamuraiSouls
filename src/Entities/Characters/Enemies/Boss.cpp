#include "Entities/Characters/Enemies/Boss.hpp"
using namespace Entities::Characters::Enemies;

const float Boss::bossAtkTime(4.0);

Boss::Boss(sf::Vector2f pos, FireBall *fireball ,Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Boss, pos, sf::Vector2f(BOSS_WIDTH, BOSS_HEIGHT), BOSS_HP, BOSS_DMG, p1, p2),
    fireball(fireball)
{
    initializeSprite();
    setFacingLeft(true);
}

Boss::~Boss(){}

void Boss::initializeSprite(){
    animator.initializeTexture(BOSS_DIR, sf::Vector2u(16,4));
}

void Boss::render(){
    animator.render();
}

void Boss::update(float dt){

    if(hp<=0){
        setIsShowing(false);
        fireball->setIsShowing(false);
        return;
    }

    speed = sf::Vector2f(speed.x, speed.y + GRAVITY * dt);

    if(speed.y > MAX_SPEED_Y)
        speed = sf::Vector2f(speed.x, MAX_SPEED_Y);

    move({speed.x * dt, speed.y * dt});

    movementBoss();

    //Attack
    if(isAttacking){ //Tempo da animacao difere do tempo do CD de ataque
        timeFromAtk += dt;
        speed.x = 0;
        if(timeFromAtk<1.12)
            animator.update(position, (int) EnemySprite::Attack, 16, dt, getFacingLeft(), 0.07);
        else
            fire();
    
    //Run
    }else if(abs(speed.x)>0.f){
        animator.update(position, (int) EnemySprite::Run, 9, dt, getFacingLeft(), 0.07);

    //Idle
    }else{
        animator.update(position, (int) EnemySprite::Idle, 9, dt, getFacingLeft(), 0.07);
    }

    atkCD += dt;
    if(atkCD >= bossAtkTime && !fireball->getIsShowing() && getIsShowing()){
        if(abs(getNearestPlayer()->getPosition().x - position.x) <= BOSS_ATK_RANGE)
            isAttacking = true;
        if(getNearestPlayer()->getPosition().x - position.x > 0)
            setFacingLeft(false);
        else
            setFacingLeft(true);
        atkCD = 0.f;
    }
}

void Boss::fire(){
    if(getFacingLeft())
        fireball->shoot(position, {- FIREBALL_SPEED_X, 0});
    else
        fireball->shoot(position, {FIREBALL_SPEED_X, 0});
    isAttacking = false;
    timeFromAtk = 0.f;
}

void Boss::movementBoss(){
    float deltaX = getNearestPlayer()->getPosition().x - position.x;
    if(abs(deltaX)<BOSS_DX_MAX && abs(deltaX)>BOSS_DX_MIN){
        if(deltaX>0){
            setSpeed(sf::Vector2f(BOSS_SPEED_X, getSpeed().y));
            setFacingLeft(false);
        }else{
            setSpeed(sf::Vector2f(- BOSS_SPEED_X, getSpeed().y));
            setFacingLeft(true);
        }
    }else{
        setSpeed(sf::Vector2f(0.f, getSpeed().y));
    }
}