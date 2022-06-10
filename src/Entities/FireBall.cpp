#include "Entities/FireBall.hpp"
using namespace Entities;

FireBall::FireBall(sf::Vector2f position, const bool direction):
    Entity(Type::FireBall, position, {FIREBALL_WIDTH, FIREBALL_HEIGHT})
{
    initializeSprite();
    setFacingLeft(direction);
}

FireBall::~FireBall(){}

void FireBall::initializeSprite(){
    animator->initializeTexture(FIREBALL_DIR, {7, 2});
}

void FireBall::render(){
    animator->render();
}

void FireBall::update(float dt){

    //MUDAR PARA ALGUM CALCULO DE ATRITO COM O AR
    speed = sf::Vector2f(speed.x, speed.y + (GRAVITY-AIR_RESISTANCE) * dt);
    if(speed.y > 20)
        speed.y = 20;

    move({speed.x * dt , speed.y * dt});
    
}

void FireBall::save(){}

void FireBall::collide(Entity *other, sf::Vector2f intersect){
    Type type = other->getType();

    switch(type){
        case Type::Pavement:
            setIsShowing(false);
            break;
        case Type::Box:
            setIsShowing(false);
            break;
        case Type::Barrel:
            setIsShowing(false);
            break;
        
        case Type::Player:
            setIsShowing(false);
            (static_cast<Characters::Character*>(other))->receiveDMG(FIREBALL_DMG);
            break;
    }
}