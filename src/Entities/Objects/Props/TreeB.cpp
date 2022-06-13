#include "Entities/Objects/Props/TreeB.hpp"
using namespace Entities::Objects::Props;

TreeB::TreeB(sf::Vector2f position):
    Object(Type::TreeB, position, sf::Vector2f(TREE_B_WIDTH, TREE_B_HEIGHT))
{
    initializeSprite();
}

TreeB::~TreeB(){}

void TreeB::initializeSprite(){
    animator.initializeTexture(TREE_B_DIR, {1, 1});
}

void TreeB::update(float dt){}