#include "States/MainMenu.hpp"
#include <vector>
#include "Graphics/Button.hpp"

using namespace States;

MainMenuState::MainMenuState(Game* stateMachine):
State(Patterns::StateId::MainMenu,stateMachine),
Menu(MAIN_MENU_BACKGROUND_DIR)
{
    addButton(new Graphics::Button("teste 1"));
    addButton(new Graphics::Button("teste 2"));
    addButton(new Graphics::Button("teste 3"));
}

MainMenuState::~MainMenuState(){}

void MainMenuState::execute(){
    if(!getIsShowing()) return;

    switch (buttonSelected)
    {
    case 0:
        std::cout << "Selected 0";
        break;
    default:
        break;
    }

}

void MainMenuState::render(){
    centerView();
    background.render();

    for(auto button : buttons){
        button->render();
    }
}

void MainMenuState::update(const float dt){
    setIsShowing(true);
}

void MainMenuState::reset(){
    //TODO
}