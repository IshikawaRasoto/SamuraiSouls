#include "Entities/Characters/Enemies/Minion.hpp"
using namespace Entities::Characters::Enemies;

const float Minion::attackTime(0.4);

Minion::Minion(sf::Vector2f pos, Players::Player* p1, Players::Player* p2):
    Enemy()
{}