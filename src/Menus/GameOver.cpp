#include "Menus/GameOver.hpp"

#include "Graphics/Button.hpp"

using namespace Menus;

GameOver::GameOver(StateMachine *stateMachine):
    State(StateId::GameOver,stateMachine),
    Menu(GAMEOVER_BACKGROUND_DIR),
    title("You died", {0.0f, 0.0f}, GAMEOVER_TITLE_FONT_DIR)
{

    title.setFontSize(10);
    title.setColor(sf::Color::Red);
    title.setTextAlignment(Graphics::TextAlignment::Center);

    addButton(new Graphics::Button("Back", {0.0f, 100.0f}));
}

GameOver::~GameOver(){}

void GameOver::execute(){
    if(!getIsShowing()) return;

    switch (selectedButton)
    {
    case 0:
        getStateMachine()->changeCurrentState(Patterns::StateId::MainMenu);
        break;
    default:
        break;
    }

    setIsShowing(false);
}

void GameOver::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();

    for(auto button : buttons){
        button->render();
    }

    title.render();
    graphicsManager->endDraw();
}

void GameOver::update(const float dt){
    setIsShowing(true);

    if(title.getFontSize() < GAMEOVER_TITLE_MAX_SIZE){
        title.setFontSize(title.getFontSize() + 1);
    }
}

void GameOver::reset(){

}