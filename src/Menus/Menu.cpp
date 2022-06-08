#include "Menus/Menu.hpp"
#include "config.hpp"

using namespace Menus;

Managers::GraphicsManager* Menu::graphicsManager = GraphicsManager::getInstance();
Managers::InputManager* Menu::inputManager = InputManager::getInstance();

Menu::Menu(std::string backgroundDir):
Ent(Type::Menu, {0.0f,0.0f}, {WINDOW_SIZE_X, WINDOW_SIZE_Y}),
background(backgroundDir),
control(this)
{
    buttons.clear();
    buttonSelected = -1;

    inputManager->subscribe("pressed", &control);
}

Menu::Menu():
Ent(Type::Menu, {0.0f, 0.0f}, {WINDOW_SIZE_X, WINDOW_SIZE_Y}),
control(this)
{
    buttons.clear();
    buttonSelected = -1;
}

Menu::~Menu(){
    for(auto button : buttons){
        delete button;
    }

    buttons.clear();
}

Managers::Control::MenuControl* Menu::getMenuControl(){
    return &control;
}

void Menu::selectUp(){
    if(buttonSelected == -1) return;
    if(!getIsShowing()) return;

    buttons[buttonSelected]->select(false);
    buttonSelected--;

    if(buttonSelected < 0){
        buttonSelected = buttons.size()-1;
    }

    buttons[buttonSelected]->select(true);
}

void Menu::selectDown(){
    if(buttonSelected == -1) return;
    if(!getIsShowing()) return;

    buttons[buttonSelected]->select(false);
    buttonSelected++;

    if(buttonSelected >= buttons.size()){
        buttonSelected = 0;
    }

    buttons[buttonSelected]->select(true);
}

void Menu::centerView(){
    graphicsManager->centerView({0, 0});
}

void Menu::addButton(Graphics::Button *button){
    if(button == nullptr) return;

    if(buttonSelected == -1){
        buttonSelected = 0;
        button->select(true);
    }

    buttons.push_back(button);
}

void Menu::initializeSprite(){}

void Managers::Control::MenuControl::update(Managers::InputManager *subject){
    if(!menu){
        std::cout << "[MenuControl] Falha ao atualizar. Menu é um ponteiro nulo.\n";
        return;
    }

    std::string event = subject->getCurrentEvent();
    std::string key = subject->getCurrentKey();

    if(event != "pressed") return;

    if(key == keys.up){
        menu->selectUp();
    }else if(key == keys.down){
        menu->selectDown();
    }else if(key == keys.execute){
        menu->execute();
    }
}