#include "Entities/Characters/Players/Huntress.hpp"
using namespace Entities::Characters;

Players::Huntress::Huntress(sf::Vector2f position, const bool isPlayerOne, InputManager* pIM):
        points(0),
        isWalking(false),
        Character(Type::Huntress, position, sf::Vector2f(HUNTRESS_WIDTH, HUNTRESS_HEIGHT), HUNTRESS_HP)
{
    initializeSprite();
}

Players::Huntress::~Huntress(){}

void Players::Huntress::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    
    animation->update(position);
}

void Players::Huntress::walk(Direction dirX, Direction dirY){

    sf::Vector2f newSpeed = speed;
    this->dirX = dirX;
    this->dirY = dirY; 

    if(dirX == Direction::Right){
        newSpeed.x = HUNTRESS_SPEED_X;
    }else if (dirX == Direction::Left){
        newSpeed.x = - HUNTRESS_SPEED_X;
    }else if(dirX == Direction::Idle){
        newSpeed.x = 0;
    }

    if(dirY == Direction::Up){
        newSpeed.y = - HUNTRESS_SPEED_Y;
    }else if(dirY == Direction::Down){
        newSpeed.y = HUNTRESS_SPEED_Y;
    }else if(dirY == Direction::Idle){
        newSpeed.y = 0;
    }

    speed = newSpeed;
}

void Players::Huntress::render(){
    animation->render();
}

void Players::Huntress::initializeSprite(){
    sf::RectangleShape *body = animation->getRectangleShape();
    body->setFillColor(sf::Color::Green);   
}

void Players::Huntress::collide(Entities::Entity* other, sf::Vector2f intersect){
    if(other->getType() == Type::Box){
        setSpeed({0, speed.y});

        position.x += intersect.x;
        position.y += intersect.y;
    };
}