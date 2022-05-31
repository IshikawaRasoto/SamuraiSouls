#include "Control/PlayerControl.hpp"

using namespace Control;

PlayerControl::PlayerControl(
    Players::Player *player, 
    std::string jump, 
    std::string left, 
    std::string right, 
    std::string attack
):keys(jump, left, right, attack){
    this->player = player;
}

PlayerControl::~PlayerControl(){}

void PlayerControl::update(Managers::InputManager *subject){
    if(!player) return;

    std::string key = subject->getCurrentKey();
    std::string event = subject->getCurrentEvent();

    if(event == "pressed"){
        if(key == keys.left){
            player->walk(Direction::Left);
        }else if(key == keys.right){
            player->walk(Direction::Right);
        }else if(key == keys.jump){
            player->jump();
        }else if(key == keys.attack){
            player->setIsAttacking(true);
        }
    }else if(event == "released"){
        if(key == keys.left || key == keys.right){
            player->walk(Direction::Idle);
        }
    }
}

Players::Player* PlayerControl::getPlayer(){
    return player;
}

void PlayerControl::setPlayer(Players::Player* player){
    this->player = player;
}