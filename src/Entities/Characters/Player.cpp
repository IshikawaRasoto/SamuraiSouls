#include "Entities/Characters/Player.hpp"
#include <iostream>
using namespace Entities::Characters;

const float Player::playerAtkTime(0.42); 
int Player::points(0);
int Player::lifes(3);

Player::Player(sf::Vector2f position, const bool isPlayerOne, Control::PlayerControl* playerControl):
        isWalking(false),
        canJump(false),
        playerOne(isPlayerOne),
        timeFromAtk(0.f),
        Character(Type::Player, position, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_HP, PLAYER_DMG)
{
    if(!playerControl){
        playerControl = new Control::PlayerControl();
    }

    playerControl->setPlayer(this);
    this->playerControl = playerControl;

    initializeSprite();
}

Player::~Player(){}

const bool Player::getIsPlayerOne() const {return playerOne;}

const int Player::getPts(){return points;}

Control::PlayerControl* Player::getPlayerControl() const{
    return playerControl;
}

void Player::addPts(const int pts){
    points += pts;
}

void Player::update(float dt){
    if(hp<0){
        setIsShowing(false);
        return;
    } 

    speed.y += GRAVITY * dt;
    move({speed.x * dt, speed.y * dt});

    //Attack
    if(statusAtk(dt)){
        animator->update(position, (int) PlayerSprite::Attack, 6, dt, getFacingLeft(), 0.07);
    
    //Fall
    }else if(speed.y > 150.f){
        animator->update(position, (int) PlayerSprite::Fall, 2, dt, getFacingLeft(), 0.3);
    
    //Jump
    }else if(speed.y < -100.f && !canJump){
        animator->update(position, (int) PlayerSprite::Jump, 2, dt, getFacingLeft(), 0.3);

    //Run
    }else if(abs(speed.x)>0){
        animator->update(position, (int) PlayerSprite::Run, 8, dt, getFacingLeft(), 0.2);

    }else{
        animator->update(position, (int) PlayerSprite::Idle, 8, dt, getFacingLeft(), 0.3);
    }
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
        setFacingLeft(false);
    }else if (direction == Direction::Left){
        speed.x = -PLAYER_SPEED_X;
        setFacingLeft(true);
    }else if(dirX == Direction::Idle){
        speed.x = 0;
    }
}

void Player::render(){
    animator->update(position);
    animator->render();
}

void Player::collide(Entities::Entity* other, sf::Vector2f intersect){
    Type type = other->getType();

    if(type == Type::Box || type == Type::Pavement){
        canJump = true;
        moveOnCollision(other, intersect);
    }
}

void Player::initializeSprite(){
    if(playerOne){
        animator->initializeTexture(MASTER_DIR, sf::Vector2u(8, 6));
    }  
}

bool Player::statusAtk(const float dt){
    if(isAttacking){
        std::cout << "Definitely Atking" << std::endl;
        //speed.x = 0.f;
        timeFromAtk += dt;
        if(timeFromAtk < playerAtkTime){
            return true;
        }
        timeFromAtk = 0;
        isAttacking = false;
    }
    return false;
}

void Player::save(){
    //TODO
}

void Control::PlayerControl::update(Managers::InputManager *subject){
    if(!player) return;

    std::string key = subject->getCurrentKey();
    std::string event = subject->getCurrentEvent();

    if(event == "pressed"){
        if(key == keys.left){
            player->walk(Characters::Direction::Left);
        }else if(key == keys.right){
            player->walk(Characters::Direction::Right);
        }else if(key == keys.jump){
            player->jump();
        }else if(key == keys.attack){
            std::cout << "ATK" << std::endl;
            player->setIsAttacking(true);
        }
    }else if(event == "released"){
        if(key == keys.left || key == keys.right){
            player->walk(Characters::Direction::Idle);
        }
    }
}