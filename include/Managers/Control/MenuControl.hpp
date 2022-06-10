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

public:

    MenuControl(
        Menus::Menu* menu = nullptr,
        std::string up = "W",
        std::string down = "S",
        std::string execute = "Enter"
    );

    ~MenuControl();

    Menus::Menu* getMenu();
    
    void update(Managers::InputManager *subject);
};

}
}

