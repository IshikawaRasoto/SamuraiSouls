#include "Entities/Characters/Player.hpp"
#include <iostream>
using namespace Entities::Characters;

int Player::points(0);
int Player::lifes(3);

Player::Player(sf::Vector2f position, const bool p1, InputManager* pIM):
        isWalking(false),
        canJump(false),
        playerOne(p1),
        Character(Type::Player, position, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_HP, PLAYER_DMG)
{
    initializeSprite();
}

Player::~Player(){}

const bool Player::getIsPlayerOne() const {return playerOne;}

const int Player::getPts(){return points;}

void Player::addPts(const int pts){
    points += pts;
}

void Player::update(float dt){
    speed.y += GRAVITY * dt;
    position.y += speed.y * dt;

    position.x += speed.x * dt;

    std::cout << position.y << "\n";
}

void Player::jump(){
    if(canJump){
        speed.y = -PLAYER_SPEED_Y;
        canJump = false;
    }
}

void Player::walk(Direction direction){

    if(direction == Direction::Right){
        speed.x = PLAYER_SPEED_X;
    }else if (direction == Direction::Left){
        speed.x = -PLAYER_SPEED_X;
    }else if(dirX == Direction::Idle){
        speed.x = 0;
    }
}

void Player::render(){
    animator->update(position);
    animator->render();
}

void Player::collide(Entities::Entity* other, sf::Vector2f intersect){
    if(other->getType() == Type::Box){
        moveOnCollision(other, intersect);
        canJump = true;
    };
}

void Player::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Green);   
}

void Player::save(){
    //TODO
}