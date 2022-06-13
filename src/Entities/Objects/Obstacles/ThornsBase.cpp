#include "Entities/Objects/Obstacles/ThornsBase.hpp"
using namespace Entities::Objects::Obstacles;

ThornsBase::ThornsBase(sf::Vector2f position):
    Object(Type::ThornsBase, position, sf::Vector2f(THORNSBASE_WIDTH, THORNSBASE_HEIGHT))
{
    initializeSprite();
}

ThornsBase::~ThornsBase(){}

void ThornsBase::initializeSprite(){
    animator.initializeTexture(THORNSBASE_DIR, {1, 1});
}


void ThornsBase::update(float dt){}