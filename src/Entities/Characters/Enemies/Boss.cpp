#include "Entities/Characters/Enemies/Boss.hpp"
using namespace Entities::Characters::Enemies;

const float Boss::bossAtkTime(4.0);

Boss::Boss(sf::Vector2f pos, FireBall *fireball ,Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Boss, pos, sf::Vector2f(BOSS_WIDTH, BOSSH_HEIGHT), BOSS_HP, BOSS_DMG, p1, p2),
    fireball(fireball)
{
    initializeSprite();
}

Boss::~Boss(){//
}

void Boss::initializeSprite(){
    animator->initializeTexture(BOSS_DIR, sf::Vector2u(16,4));
}

void Boss::render(){
    animator->render();
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
    if((atkCD >= bossAtkTime) && abs(getNearestPlayer()->getPosition().x - position.x) <= BOSS_ATK_RANGE && abs(getNearestPlayer()->getPosition().y - position.y) <= ATK_RANGE_Y)
        fire();
}

void Boss::fire(){
    if(getFacingLeft())
        fireball->shoot(position, {- FIREBALL_SPEED_X, 0});
    else
        fireball->shoot(position, {FIREBALL_SPEED_X, 0});
}

void Boss::save(){
    //TODO
}

void Boss::movementBoss(){

}