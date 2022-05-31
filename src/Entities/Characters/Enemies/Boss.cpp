#include "Entities/Characters/Enemies/Boss.hpp"
using namespace Entities::Characters::Enemies;

const float attackTime(0.4);

Boss::Boss(sf::Vector2f pos, Players::Player* p1, Players::Player* p2):
    Enemy(Type::Boss, pos, sf::Vector2f(BOSS_WIDTH, BOSSH_HEIGHT), BOSS_HP, BOSS_DMG, p1, p2)
    
{}

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