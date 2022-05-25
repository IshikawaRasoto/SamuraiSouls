#include "Entities/Objects/Obstacles/Box.hpp"
using namespace Entities::Objects;

Obstacles::Box::Box(sf::Vector2f position):
    Object(Type::Box, position, sf::Vector2f(BOX_WIDTH, BOX_HEIGHT))
    {
            initializeSprite();

    }

Obstacles::Box::~Box(){}

void Obstacles::Box::update(const float dt){
    animation->update(position);
}
void Obstacles::Box::render(){
    animation->render();
}
void Obstacles::Box::initializeSprite(){
    sf::RectangleShape* body = animation->getRectangleShape();
    body->setFillColor(sf::Color::White);
}