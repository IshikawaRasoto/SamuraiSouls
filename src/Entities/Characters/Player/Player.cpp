#include "Entities/Characters/Players/Player.hpp"
#include <iostream>

using namespace Entities::Characters::Players;

int Player::points(0);
int Player::lifes(3);

Player::Player(sf::Vector2f position, const bool p1, InputManager* pIM):
        isWalking(false),
        playerOne(p1),
        Character(Type::Player, position, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_HP, PLAYER_DMG)
{
    initializeSprite();
}

Player::~Player(){}

const bool Player::isPlayerOne() const {return playerOne;}

const int Player::getPts(){return points;}

void Player::addPts(const int pts){
    points += pts;
}

void Player::update(float dt){
    setPosition({position.x + speed.x * dt, position.y + speed.y * dt});
    animator->update(position);
}

void Player::jump(){
    //TODO
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
    animator->render();
}

void Player::collide(Entities::Entity* other, sf::Vector2f intersect){
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

void Player::initializeSprite(){
    sf::RectangleShape *body = animator->getRectangleShape();
    body->setFillColor(sf::Color::Green);   
}

void Player::save(){
    //TODO
}