#include "Entities/Objects/Obstacles/Box.hpp"
using namespace Entities::Objects::Obstacles;

Box::Box(sf::Vector2f position):
    Object(Type::Box, position, sf::Vector2f(BOX_WIDTH, BOX_HEIGHT))
    {
        initializeSprite();
    }

Box::~Box(){}

void Box::update(const float dt){
    animator->update(position);
}
void Box::render(){
    animator->render();
}
void Box::initializeSprite(){
    sf::RectangleShape* body = animator->getRectangleShape();
    body->setFillColor(sf::Color::White);
}

void Box::save(){
    //TODO
}