#pragma once

#include "Entities/Characters/Player.hpp"
#include "Patterns/Observer.hpp"
#include "Managers/Input.hpp"
#include "PlayerKeys.hpp"

#include <string>

using namespace Entities;

namespace Control{

class PlayerControl : public Observer<Managers::InputManager>{
private:

    Characters::Player *player;
    PlayerKeys keys;

public:
    PlayerControl(
        Characters::Player *player = nullptr,
        std::string jump = "W", 
        std::string left = "A", 
        std::string right = "D", 
        std::string attack = "Enter"
    );
    
    ~PlayerControl();

    void update(Managers::InputManager *subject);

    Characters::Player* getPlayer();
    void setPlayer(Characters::Player* player);
};

}

