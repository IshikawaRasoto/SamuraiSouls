#include "Entities/Objects/Obstacles/Box.hpp"
using namespace Entities::Objects::Obstacles;

Box::Box(sf::Vector2f position):
    Object(Type::Box, position, sf::Vector2f(BOX_WIDTH, BOX_HEIGHT))
    {
        initializeSprite();
    }

Box::~Box(){}


void Box::initializeSprite(){
    animator->initializeTexture(BOX_DIR, sf::Vector2u(1,1));
    animator->update(position);
}

void Box::save(){
    //TODO
}