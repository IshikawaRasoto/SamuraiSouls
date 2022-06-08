#pragma once

#include "States/Level.hpp"
#include "Patterns/StateMachine.hpp"

#include <string>

#define FIRST_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackGround.png"


namespace States{

class FirstLevel : public States::Level{
public:

    FirstLevel(Patterns::StateMachine* stateMachine);
    ~FirstLevel();
    
    void reset();
    void centerView();
};


} // namespace States
