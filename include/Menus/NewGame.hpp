#pragma once

#include "./Menu.hpp"

#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#define NEWGAME_BACKGROUND_DIR "./Textures/Menus/MainMenu.png"
#define NEWGAME_FONT_DIR "./fonts/SpecialElite.ttf"
#define NEWGAME_TITLE_FONT_SIZE 50

namespace Menus{

class NewGame : public Patterns::State, public Menu{
private:
    Graphics::Text title;
public:
    NewGame(StateMachine *stateMachine);
    ~NewGame();

    void update(const float dt);
    void render();
    void execute();
    void reset();
};

}
