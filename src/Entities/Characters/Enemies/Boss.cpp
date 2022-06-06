#include "Entities/Characters/Enemies/Boss.hpp"
using namespace Entities::Characters::Enemies;

const float bossAtkTime(0.4);

Boss::Boss(sf::Vector2f pos, Characters::Player* p1, Characters::Player* p2):
    Enemy(Type::Boss, pos, sf::Vector2f(BOSS_WIDTH, BOSSH_HEIGHT), BOSS_HP, BOSS_DMG, p1, p2)
{
    initializeSprite();
}

Boss::~Boss(){//
}

void Boss::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Red);
}

void Boss::render(){
    animator->render();
}

void Boss::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    animator->update(position);
}

void Boss::attack(){
    //TODO
}

void Boss::save(){
    //TODO
}