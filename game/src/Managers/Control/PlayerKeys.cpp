#include "Managers/Control/PlayerKeys.hpp"

using namespace Managers::Control;

PlayerKeys::PlayerKeys(
    const std::string jump, 
    const std::string left, 
    const std::string right, 
    const std::string attack
){
    this->jump = jump;
    this->left = left;
    this->right = right;
    this->attack = attack;
}

PlayerKeys::PlayerKeys(){
    jump = "";
    left = "";
    right = "";
    attack = "";
}