#include "Menus/Menu.hpp"
#include "config.hpp"

using namespace Menus;

Managers::GraphicsManager* Menu::graphicsManager = GraphicsManager::getInstance();

Menu::Menu(std::string backgroundDir):
Ent(Type::Menu, {0.0f,0.0f}, {WINDOW_SIZE_X, WINDOW_SIZE_Y}),
background(backgroundDir)
{
    buttons.clear();
    buttonSelected = -1;
}

Menu::Menu():
Ent(Type::Menu, {0.0f, 0.0f}, {WINDOW_SIZE_X, WINDOW_SIZE_Y})
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
    graphicsManager->centerView({WINDOW_SIZE_X/2, WINDOW_SIZE_Y/2});
}

void Menu::addButton(Graphics::Button *button){
    if(button == nullptr) return;

    if(buttonSelected == -1){
        buttonSelected = 0;
    }

    buttons.push_back(button);
}

void Menu::initializeSprite(){}