#pragma once

#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "Menus/Menu.hpp"
#include "Graphics/Text.hpp"

#define MAIN_MENU_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackground.png"
#define MAIN_MENU_TITLE_FONT_DIR "./fonts/SpecialElite.ttf"

namespace Menus{

class MainMenu : public Patterns::State, public Menus::Menu{
private:
    Graphics::Text title;

public:

    MainMenu(StateMachine* stateMachine);
    ~MainMenu();

    void execute();

    void render();
    void update(const float dt);
    void reset();
};

}