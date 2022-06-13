#include "Entities/Characters/Player.hpp"
#include <iostream>
using namespace Entities::Characters;

const float Player::playerAtkTime(0.54); 
int Player::points(0);

Player::Player(sf::Vector2f position, const bool isPlayerOne, Control::PlayerControl* playerControl):
        isWalking(false),
        canJump(false),
        playerOne(isPlayerOne),
        timeFromAtk(0.f),
        atkCollision(false),
        atkCD(1.0),
        Character(Type::Player, position, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), PLAYER_HP, PLAYER_DMG)
{
    if(!playerControl){
        if(!playerOne){
            this->playerControl = new PlayerControl(this, "Up", "Left", "Right", "RControl");
        }else{
            this->playerControl = new PlayerControl(this);
        }
    }

    initializeSprite();
}

Player::~Player(){}

const bool Player::getIsPlayerOne() const {return playerOne;}

const int Player::getPts(){return points;}

const bool Player::getIsAtkCollision() const {return atkCollision;}

Control::PlayerControl* Player::getPlayerControl() const{
    return playerControl;
}

void Player::setAtkCollision(const bool atkCollision){
    this->atkCollision = atkCollision;
}

void Player::addPts(const int pts){
    points += pts;
}

void Player::setPts(const int pts){
    points = pts;
}

void Player::setHp(int hp){
    this->hp = hp;
}

void Player::update(float dt){
    if(hp<=0){
        setIsShowing(false);
        return;
    } 

    speed.y += GRAVITY * dt;
    move({speed.x * dt, speed.y * dt});

    if(position.y >= PLAYER_MAX_Y){
        hp = 0;
    }

    //Attack
    if(statusAtk(dt)){
        animator.update(position, (int) PlayerSprite::Attack, 6, dt, getFacingLeft(), 0.09);
    
    //Fall
    }else if(speed.y > 150.f){
        animator.update(position, (int) PlayerSprite::Fall, 2, dt, getFacingLeft(), 0.3);
    
    //Jump
    }else if(speed.y < -100.f && !canJump){
        animator.update(position, (int) PlayerSprite::Jump, 2, dt, getFacingLeft(), 0.3);

    //Run
    }else if(abs(speed.x)>0){
        animator.update(position, (int) PlayerSprite::Run, 8, dt, getFacingLeft(), 0.2);

    //Idle
    }else{
        animator.update(position, (int) PlayerSprite::Idle, 8, dt, getFacingLeft(), 0.3);
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
    animator.update(position);
    animator.render();
}

void Player::collide(Entity* other, sf::Vector2f intersect){
    
    Type type = other->getType();
    //std::cout << type << "Collided with player" << std::endl;

    switch (type){
        case Type::Pavement:
            canJump = true;
            moveOnCollision(other, intersect);
            break;
        case Type::Box:
            canJump = true;
            moveOnCollision(other, intersect);
            break;
        case Type::Barrel:
            canJump = true;
            moveOnCollision(other, intersect);
            break;
        case Type::InvisibleBlock:
            moveOnCollision(other, intersect);
            break;
        case Type::Thorns:
            receiveDMG(100);
            break;
        case Type::Ground:
            canJump = true;
            moveOnCollision(other, intersect);
            break;
        case Type::MiniGround:
            canJump = true;
            moveOnCollision(other, intersect);
            break;
        case Type::Gravestone:
            canJump = true;
            moveOnCollision(other, intersect);
            break;
    }
}

void Player::playerAtk(Entities::Entity *other, Type t){
    if(atkCD < playerAtkTime)
        atkCollision = false;

    if(!isAttacking || !atkCollision)
        return;
    
    float deltaX = other->getPosition().x - position.x;
    float deltaY = other->getPosition().y - position.y;

    if(abs(deltaY)<PLAYER_ATK_RANGE_Y && abs(deltaX)<PLAYER_ATK_RANGE_X && isAttacking){ //69 é altura da sprite de ataque
        atkCD = 0.f;
        atkCollision = false;
        (static_cast<Character*>(other))->receiveDMG(PLAYER_DMG);
        if((static_cast<Character*>(other))->getHP()<=0){
            switch(t){
                case Type::Goblin:
                    points += 50;
                    break;
                case Type::Skeleton:
                    points += 100;
                    break;
                case Type::Boss:
                    points += 500;
                    break;
            }
        }
        
    }
}

void Player::initializeSprite(){
    if(playerOne)
        animator.initializeTexture(MASTER_DIR, sf::Vector2u(8, 6));
    else
        animator.initializeTexture(APPRENTICE_DIR, sf::Vector2u(8, 6));
}

bool Player::statusAtk(const float dt){
    if(isAttacking){
        timeFromAtk += dt;
        atkCD += dt;
        if(timeFromAtk < playerAtkTime){
            return true;
        }

        //atkCollision = true;

        timeFromAtk = 0;
        isAttacking = false;
    }
    return false;
}

Snapshots::PlayerSnapshot* Player::save(){
    return new Snapshots::PlayerSnapshot(
        playerOne,
        hp,
        position,
        speed,
        getFacingLeft()
    );
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
            //std::cout << "ATK" << std::endl;
            player->setIsAttacking(true);
            player->setAtkCollision(true);
        }
    }else if(event == "released"){
        if(key == keys.left || key == keys.right){
            player->walk(Characters::Direction::Idle);
        }
    }
}