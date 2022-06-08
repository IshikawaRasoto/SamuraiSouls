#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
using namespace Entities::Objects::Surfaces;

InvisibleBlock::InvisibleBlock(sf::Vector2f position):
    Object(Type::InvisibleBlock, position, {BLOCK_HEIGHT, BLOCK_WIDTH})
{
    initializeSprite();
}

InvisibleBlock::~InvisibleBlock(){}

void InvisibleBlock::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Transparent);
}

void InvisibleBlock::save(){}