#pragma once

#include "Menu.hpp"
#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#define GAMEOVER_BACKGROUND_DIR "./Textures/Menus/GameOver.jpg"
#define GAMEOVER_TITLE_FONT_DIR "./fonts/SpecialElite.ttf"
#define GAMEOVER_TITLE_MAX_SIZE 100

namespace Menus{

class GameOver : public Menu, public Patterns::State{
private:
    Graphics::Text title;

public:
    GameOver(StateMachine *stateMachine);
    ~GameOver();

    void render();
    void update(const float dt);
    void execute();

    void reset();
};

}