#pragma once

#include <vector>

#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"
#include "./Menu.hpp"

#include "Graphics/Text.hpp"
#include "Data/LeaderboardItem.hpp"

#define LEADERBOARD_BACKGROUND_DIR "./Textures/Menus/Pause.png"
#define LEADERBOARD_FONT_DIR "./fonts/SpecialElite.ttf"
#define LEADERBOARD_ITEM_FONT_COLOR sf::Color::White
#define LEADERBOARD_ITEM_FONT_SIZE 25
#define LEADERBOARD_TITLE_FONT_SIZE 60
#define LEADERBOARD_MAX_ITEMS 5
#define LEADERBOARD_TEXT_LENGTH 50

namespace Menus{
class Leaderboard : public Patterns::State, public Menu{
private:
    Graphics::Text title;
    std::vector<Data::LeaderboardItem*> leaderboardItems;
    std::vector<Graphics::Text*> leaderboardTexts;

    void loadItems();
    void clearItems();
    void clearTexts();

public:
    Leaderboard(Patterns::StateMachine *stateMachine);
    ~Leaderboard();

    void execute();
    void update(const float dt);
    void render();
    void reset();
};
}