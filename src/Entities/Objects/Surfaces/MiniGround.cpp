#include "Entities/Objects/Surfaces/MiniGround.hpp"
using namespace Entities::Objects::Surfaces;

MiniGround::MiniGround(sf::Vector2f position):
    Object(Type::Pavement, position, {MINIGROUND_WIDTH, MINIGROUND_HEIGHT})
{
    initializeSprite();
}

Ground::~Ground(){}

void Ground::initializeSprite(){
    animator->initializeTexture(MINIGROUND_DIR, {1, 1});
}


void Ground::save(){}