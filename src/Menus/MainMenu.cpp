#include "Menus/MainMenu.hpp"
#include "Graphics/Button.hpp"

#include "config.hpp"

#include <vector>

using namespace Menus;

MainMenu::MainMenu(StateMachine* stateMachine):
    State(Patterns::StateId::MainMenu,stateMachine),
    Menu(MAIN_MENU_BACKGROUND_DIR),
    title(WINDOW_NAME, {0.0f, -150.0f}, MAIN_MENU_TITLE_FONT_DIR)
{
    std::vector<std::string> buttonNames = {"Jogar", "Sobre", "Sair"};

    for(float i = 0; i < buttonNames.size(); i++){
        addButton(new Graphics::Button(buttonNames[i], {0.0f, i*80}, MAIN_MENU_TITLE_FONT_DIR));
    }

    title.setFontSize(80);
    title.setTextAlignment(Graphics::TextAlignment::Center);
    title.setColor(sf::Color::White);
}

MainMenu::~MainMenu(){}

void MainMenu::execute(){
    if(!getIsShowing()) return;

    switch (selectedButton)
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

    setIsShowing(true);
}

void MainMenu::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();

    for(auto button : buttons){
        button->render();
    }

    title.render();
    graphicsManager->endDraw();
}

void MainMenu::update(const float dt){
    setIsShowing(true);

    for(auto button : buttons){
        button->update(dt);
    }
}

void MainMenu::reset(){
    //TODO
}