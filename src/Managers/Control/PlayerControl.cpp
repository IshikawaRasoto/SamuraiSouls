#include "Managers/Control/PlayerControl.hpp"

using namespace Managers::Control;

PlayerControl::PlayerControl(
    Characters::Player *player, 
    std::string jump, 
    std::string left, 
    std::string right, 
    std::string attack
):keys(jump, left, right, attack){
    this->player = player;
}

PlayerControl::~PlayerControl(){}

Characters::Player* PlayerControl::getPlayer(){
    return player;
}

void PlayerControl::setPlayer(Characters::Player* player){
    this->player = player;
}