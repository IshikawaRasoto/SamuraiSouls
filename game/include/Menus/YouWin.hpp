#pragma once

#include "Menu.hpp"
#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "Graphics/Text.hpp"

#include <string>

#define YOUWIN_BACKGROUND_DIR "./Textures/Menus/GameOver.jpg"
#define YOUWIN_TITLE_FONT_DIR "./fonts/SpecialElite.ttf"
#define YOUWIN_TITLE_START_SIZE 10
#define YOUWIN_TITLE_MAX_SIZE 100

#define YOUWIN_LEADERBOARDNAME_MAX_LENGTH 15

namespace Menus{

class YouWin : public Menu, public Patterns::State{
private:
    Graphics::Text title;
    Graphics::Text typeYourName;

    std::string name;
    Graphics::Text leaderboardName;

public:
    YouWin(StateMachine *stateMachine);
    ~YouWin();

    void saveName();
    void handleInput(std::string input);

    void render();
    void update(const float dt);
    void execute();

    void reset();
};

}