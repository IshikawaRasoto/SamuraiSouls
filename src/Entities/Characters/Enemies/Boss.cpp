#include "Entities/Characters/Enemies/Boss.hpp"
using namespace Entities::Characters;

const float attackTime(0.4);

Enemies::Boss::Boss(sf::Vector2f pos = sf::Vector2f(0.0, 0.0), Player* p1, Player* p2):
    Enemy(Type::Boss, pos, sf::Vector2f(BOSS_WIDTH, BOOS_HEIGHT), BOSS_HP, BOSS_DMG, p1, p2),
    
{}

Enemies::Boss::~Boss(){//
}