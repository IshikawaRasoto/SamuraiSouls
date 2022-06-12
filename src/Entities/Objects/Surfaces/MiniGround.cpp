#include "Entities/Objects/Surfaces/MiniGround.hpp"
using namespace Entities::Objects::Surfaces;

MiniGround::MiniGround(sf::Vector2f position):
    Object(Type::MiniGround, position, {MINIGROUND_WIDTH, MINIGROUND_HEIGHT})
{
    initializeSprite();
}

MiniGround::~MiniGround(){}

void MiniGround::initializeSprite(){
    animator.initializeTexture(MINIGROUND_DIR, {1, 1});
}


void MiniGround::save(){}

void MiniGround::update(float dt){}