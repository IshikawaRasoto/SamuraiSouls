#include "Menus/Leaderboard.hpp"
#include "Data/Leaderboard.hpp"

using namespace Menus;

Leaderboard::Leaderboard(Patterns::StateMachine* stateMachine):
    State(Patterns::StateId::Leaderboard,stateMachine),
    Menu(LEADERBOARD_BACKGROUND_DIR),
    title("LEADERBOARD:", {0.0f, -180.0f}, LEADERBOARD_FONT_DIR)
{
    title.setColor(sf::Color::White);
    title.setFontSize(LEADERBOARD_TITLE_FONT_SIZE);
    title.setTextAlignment(Graphics::TextAlignment::Center);

    loadItems();
}

Leaderboard::~Leaderboard(){
    clearItems();
    clearTexts();
}

void Leaderboard::clearItems(){
    for(auto item : leaderboardItems){
        if(item)
            delete item;
    }

    leaderboardItems.clear();
}

void Leaderboard::clearTexts(){
    for(auto text : leaderboardTexts){
        if(text)
            delete text;
    }

    leaderboardTexts.clear();
}

void Leaderboard::reset(){
    clearItems();
    clearTexts();

    loadItems();
}

void Leaderboard::loadItems(){
    leaderboardItems = Data::Leaderboard::getItems();
    if(leaderboardItems.size() == 0){
        return;
    }

    Data::Leaderboard::sort(leaderboardItems);

    for(int i = 0; i < leaderboardItems.size() && i < LEADERBOARD_MAX_ITEMS; i++){
        sf::Vector2f textPosition;

        textPosition.x = position.x;
        textPosition.y = i > 0 ? i*60.0f : 0.0f;

        std::string textValue = leaderboardItems[i]->name;
        std::string pointsString = std::to_string(leaderboardItems[i]->points);

        for(int j = textValue.length(); j < LEADERBOARD_TEXT_LENGTH-pointsString.length(); j++){
            textValue.push_back('.');
        }

        textValue += pointsString;

        Graphics::Text *text = new Graphics::Text(
            textValue,
            textPosition,
            LEADERBOARD_FONT_DIR
        );

        text->setColor(LEADERBOARD_ITEM_FONT_COLOR);
        text->setFontSize(LEADERBOARD_ITEM_FONT_SIZE);
        text->setTextAlignment(Graphics::TextAlignment::Center);

        leaderboardTexts.push_back(text);
    }
}

void Leaderboard::centerView(){
    graphicsManager->centerView({0.0f,0.0f});
}

void Leaderboard::render(){
    graphicsManager->beginDraw();

    background.render();
    title.render();

    for(auto text : leaderboardTexts){
        text->render();
    }

    graphicsManager->endDraw();
}

void Leaderboard::update(const float dt){
    setIsShowing(true);
}

void Leaderboard::execute(){
    if(!getIsShowing()) return;

    changeCurrentState(Patterns::StateId::MainMenu);

    setIsShowing(false);
}