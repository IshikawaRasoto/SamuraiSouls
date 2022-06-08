#pragma once

#include "Levels/Level.hpp"
#include "Patterns/StateMachine.hpp"

#include <string>

#define FIRST_LEVEL_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackGround.png"


namespace Levels{

class FirstLevel : public Levels::Level{
public:

    FirstLevel(Patterns::StateMachine* stateMachine);
    ~FirstLevel();
    
    void reset();
    void centerView();
};


} // namespace Levels
