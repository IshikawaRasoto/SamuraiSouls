#include "Entities/Objects/Props/TreeA.hpp"
using namespace Entities::Objects::Props;

TreeA::TreeA(sf::Vector2f position):
    Object(Type::TreeA, position, sf::Vector2f(TREE_A_WIDTH, TREE_A_HEIGHT))
{
    initializeSprite();
}

TreeA::~TreeA(){}

void TreeA::initializeSprite(){
    animator.initializeTexture(TREE_A_DIR, {1, 1});
}

void TreeA::save(){
    //TODO
}

void TreeA::update(float dt){}