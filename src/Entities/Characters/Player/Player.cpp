#include "Entities/Characters/Players/Player.hpp"
#include <iostream>

using namespace Entities::Characters;

Players::Player::Player(sf::Vector2f position, const bool isPlayerOne, InputManager* pIM):
        points(0),
        isWalking(false),
        Character(Type::Player, position, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_HP, PLAYER_DMG)
{
    initializeSprite();
}

Players::Player::~Player(){}

void Players::Player::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    animator->update(position);
}

void Players::Player::walk(Direction dirX, Direction dirY){

    sf::Vector2f newSpeed = speed;
    this->dirX = dirX;
    this->dirY = dirY; 

    if(dirX == Direction::Right){
        newSpeed.x = PLAYER_SPEED_X;
    }else if (dirX == Direction::Left){
        newSpeed.x = - PLAYER_SPEED_X;
    }else if(dirX == Direction::Idle){
        newSpeed.x = 0;
    }

    if(dirY == Direction::Up){
        newSpeed.y = - PLAYER_SPEED_Y;
    }else if(dirY == Direction::Down){
        newSpeed.y = PLAYER_SPEED_Y;
    }else if(dirY == Direction::Idle){
        newSpeed.y = 0;
    }

    speed = newSpeed;
}

void Players::Player::render(){
    animator->render();
}

void Players::Player::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Green);   
}

void Players::Player::collide(Entities::Entity* other, sf::Vector2f intersect){
    if(other->getType() == Type::Box){
        setSpeed({0, speed.y});

        std::cout << intersect.x << "|" << intersect.y << "\n"; 

        if(intersect.x > intersect.y){
            if(other->getPosition().x < position.x){
                position.x -= intersect.x;
            }else{
                position.x += intersect.x;
            }
        }else{
            if(other->getPosition().y < position.y){
                position.y -= intersect.y;
            }else{
                position.y += intersect.y;
            }
        }
    };
}