#include <iostream>

#include "Managers/Control/MenuControl.hpp"
#include "Managers/EventType.hpp"

using namespace Managers::Control;

MenuControl::MenuControl(
    Menus::Menu* menu,
    std::string up,
    std::string down,
    std::string execute
):
    keys(up,down,execute)
{
    if(menu == nullptr){
        std::cout << "[MenuControl] Erro ao criar uma nova instância de MenuControl. Esperado: \"Menu*\" | Recebido: \"nullptr\".\n";
        exit(1);
    }

    this->menu = menu;
}

MenuControl::~MenuControl(){}

Menus::Menu* MenuControl::getMenu(){
    return menu;
}