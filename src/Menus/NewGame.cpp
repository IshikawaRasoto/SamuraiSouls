#include "Menus/NewGame.hpp"

#include <vector>
#include <string>

#include "Graphics/Button.hpp"
#include "Levels/Level.hpp"

#include "Game.hpp"

using namespace Menus;

NewGame::NewGame(StateMachine *stateMachine):
    State(Patterns::StateId::NewGame, stateMachine),
    Menu(NEWGAME_BACKGROUND_DIR),
    title("Choose a mode:", {0.0f, -100.0f}, NEWGAME_FONT_DIR)
{
    std::vector<std::string> buttonNames({"Singleplayer", "Multiplayer"});

    for(int i = 0; i < buttonNames.size(); i++){
        addButton(new Graphics::Button(buttonNames[i],{0.0f, i*80.0f},NEWGAME_FONT_DIR));
    }

    title.setFontSize(NEWGAME_TITLE_FONT_SIZE);
    title.setTextAlignment(Graphics::TextAlignment::Center);
    title.setColor(sf::Color::White);
}

NewGame::~NewGame(){}

void NewGame::update(const float dt){
    setIsShowing(true);

    for(auto button : buttons){
        button->update(dt);
    }
}

void NewGame::execute(){
    if(!getIsShowing()) return;

    switch (selectedButton)
    {
    case 0:
        break;
    case 1:
        (static_cast<Game*>(stateMachine))->getCurrentLevel()->createPlayer2();
        break;
    }

    changeCurrentState((static_cast<Game*>(stateMachine))->getCurrentLevelId());
    
    setIsShowing(false);
}

void NewGame::centerView(){
    graphicsManager->centerView({0.0f, 0.0f});
}

void NewGame::render(){
    graphicsManager->beginDraw();
    centerView();

    background.render();

    title.render();

    for(auto button : buttons){
        button->render();
    }

    graphicsManager->endDraw();
}

void NewGame::reset(){}
