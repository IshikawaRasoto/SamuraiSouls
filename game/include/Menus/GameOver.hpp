#pragma once

#include "Menu.hpp"
#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define GAMEOVER_BACKGROUND_DIR "./Textures/Menus/GameOver.jpg"
#define GAMEOVER_TITLE_FONT_DIR "./fonts/SpecialElite.ttf"
#define GAMEOVER_TITLE_START_SIZE 10
#define GAMEOVER_TITLE_MAX_SIZE 100

#define GAMEOVER_LEADERBOARDNAME_MAX_LENGTH 15

namespace Menus{

class GameOver : public Menu, public Patterns::State{
private:
    Graphics::Text title;
    Graphics::Text typeYourName;

    std::string name;
    Graphics::Text leaderboardName;

public:
    GameOver(StateMachine *stateMachine);
    ~GameOver();

    void saveName();
    void handleInput(std::string key);

    void render();
    void update(const float dt);
    void execute();

    void reset();
};

}