#include "Entities/Objects/Surfaces/Platform.hpp"

using namespace Entities::Objects::Surfaces;

Platform::Platform(sf::Vector2f position):
    Object(Type::Platform, position, {PLATFORM_WIDTH, PLATFORM_HEIGHT})
{
    initializeSprite();
}

Platform::~Platform(){}

void Platform::update(float dt){
    animator->update(position);
}

void Platform::initializeSprite(){
    animator->getRectangleShape()->setFillColor(sf::Color::Cyan);
}

void Platform::save(){}