#pragma once

#include "Entities/Characters/Players/Player.hpp"
#include "Patterns/Observer.hpp"
#include "Managers/Input.hpp"
#include "PlayerKeys.hpp"

#include <string>

using namespace Entities::Characters;

namespace Control{

class PlayerControl : public Observer<Managers::InputManager>{
private:

    Players::Player *player;
    PlayerKeys keys;

public:
    PlayerControl(
        Players::Player *player = nullptr,
        std::string jump = "W", 
        std::string left = "A", 
        std::string right = "D", 
        std::string attack = "Enter"
    );
    
    ~PlayerControl();

    void update(Managers::InputManager *subject);

    Players::Player* getPlayer();
    void setPlayer(Players::Player* player);
};

}

