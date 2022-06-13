#include "Menus/Pause.hpp"
#include "Graphics/Button.hpp"
#include "Patterns/StateMachine.hpp"

#include <vector>

using namespace Menus;

Pause::Pause(StateMachine *stateMachine):
    Menu(PAUSE_BACKGROUND_DIR),
    State(Patterns::StateId::Pause, stateMachine),
    title("Game paused", {0.0f,-140.0f}, PAUSE_FONT_DIR)
{
    std::vector<std::string> buttonNames = {"Continuar", "Salvar", "Carregar", "Sair"};

    for(int i = 0; i < buttonNames.size(); i++){
        addButton(new Graphics::Button(buttonNames[i], {0.0f, 0.0f + PAUSE_MARGIN_BUTTON*i}, PAUSE_FONT_DIR));
    }

    title.setFontSize(64);
    title.setTextAlignment(Graphics::TextAlignment::Center);
}

Pause::~Pause(){}

void Pause::render(){
    graphicsManager->beginDraw();

    centerView();

    background.render();

    for(auto &button : buttons){
        button->render();
    }

    title.render();

    graphicsManager->endDraw();
}

void Pause::update(const float dt){
    setIsShowing(true);

    for(auto &button : buttons){
        button->update(dt);
    }
}

void Pause::execute(){
    if(!getIsShowing()) return;

    Levels::Level *currentLevel = Levels::Level::getCurrentLevel();

    switch (selectedButton)
    {
    case 0:
        changeCurrentState(getStateMachine()->getLastState());
        break;
    case 1:
        if(currentLevel){
            currentLevel->save();
        }
        break;
    case 2:
        if(currentLevel){
            currentLevel->load();
        }
        break;
    case 3:
        changeCurrentState(Patterns::StateId::MainMenu);

        break;
    default:
        break;
    }

    setIsShowing(false);
}

void Pause::reset(){
    //TODO
}