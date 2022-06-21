#pragma once

#include "MenuKeys.hpp"
#include "Patterns/Observer.hpp"
#include "Managers/Input.hpp"

#include <string>

namespace Menus{
    class Menu;
}

namespace Managers{
namespace Control{

class MenuControl : public Patterns::Observer<Managers::InputManager>{
private:
    Menus::Menu* menu;
    MenuKeys keys;
    bool menuHasInput;
public:

    MenuControl(
        Menus::Menu* menu = nullptr,
        std::string up = "W",
        std::string down = "S",
        std::string execute = "Enter"
    );

    ~MenuControl();

    bool getMenuHasInput();
    Menus::Menu* getMenu();
    
    void setMenuHasInput(bool menuHasInput);

    void update(Managers::InputManager *subject);
};

}
}

