#include "States/MainMenu.hpp"
#include <vector>
#include "Graphics/Button.hpp"

using namespace States;

MainMenuState::MainMenuState(Game* stateMachine):
    State(Patterns::StateId::MainMenu,stateMachine),
    Menu(MAIN_MENU_BACKGROUND_DIR)
{
    std::vector<std::string> buttonNames = {"Jogar", "Sobre", "Sair"};

    for(float i = 0; i < buttonNames.size(); i++){
        addButton(new Graphics::Button(buttonNames[i], {0.0f, i*80}));
    }
}

MainMenuState::~MainMenuState(){}

void MainMenuState::execute(){
    if(!getIsShowing()) return;

    switch (buttonSelected)
    {
    case 0:
        getStateMachine()->changeCurrentState(Patterns::StateId::FirstLevel);
        break;
    case 1:
        break;
    case 2:
        graphicsManager->setDone(true);
    default:
        break;
    }

}

void MainMenuState::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();

    for(auto button : buttons){
        button->render();
    }

    graphicsManager->endDraw();
}

void MainMenuState::update(const float dt){
    setIsShowing(true);

    for(auto button : buttons){
        button->update(dt);
    }
}

void MainMenuState::reset(){
    //TODO
}