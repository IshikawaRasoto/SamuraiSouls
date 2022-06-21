#include "Entities/Objects/Props/Bush.hpp"
using namespace Entities::Objects::Props;

Bush::Bush(sf::Vector2f position):
    Object(Type::Bush, position, {BUSH_WIDTH, BUSH_HEIGHT})
    {
        initializeSprite();
    }

Bush::~Bush(){}

void Bush::initializeSprite(){
    animator.initializeTexture(BUSH_DIR, {1,1});
}

void Bush::update(float dt){}