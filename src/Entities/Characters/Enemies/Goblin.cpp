#include "Entities/Characters/Enemies/Goblin.hpp"
using namespace Entities::Characters::Enemies;

const float Goblin::attackTime(0.4);

Goblin::Goblin(sf::Vector2f pos, Players::Player* p1, Players::Player* p2):
    Enemy(Type::Goblin, pos, sf::Vector2f(GOBLIN_WIDTH, GOBLIN_HEIGHT), GOBLIN_HP, GOBLIN_DMG, p1, p2)
{
    initializeSprite();
}

Goblin::~Goblin(){}

void Goblin::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Red);
}

void Goblin::render(){
    animator->render();
}

void Goblin::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    animator->update(position);
}

void Goblin::attack(){
    //TODO
}

void Goblin::save(){
    //TODO
}