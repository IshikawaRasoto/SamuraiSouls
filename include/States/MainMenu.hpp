#pragma once

#include "Patterns/State.hpp"
#include "Menus/Menu.hpp"
#include "Game.hpp"

#define MAIN_MENU_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackGround.png"

namespace States{

class MainMenuState : public Patterns::State, public Menus::Menu{
private:

public:

    MainMenuState(Game* stateMachine);
    ~MainMenuState();

    void execute();

    void render();
    void update(const float dt);
    void reset();
};

}