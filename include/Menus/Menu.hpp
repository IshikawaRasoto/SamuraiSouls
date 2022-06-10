#pragma once

#include <vector>
#include <string>
#include "Graphics/Button.hpp"
#include "Graphics/Background.hpp"

#include "Managers/Graphics.hpp"
#include "Managers/Input.hpp"
#include "Managers/Control/MenuControl.hpp"
 
namespace Managers{
namespace Control{
    class MenuControl;
}
}

namespace Menus{

class Menu : public Ent{
protected:
    std::vector<Graphics::Button*> buttons;
    int selectedButton;
    Graphics::Background background;

    static Managers::GraphicsManager* graphicsManager;
    static Managers::InputManager* inputManager;

    Managers::Control::MenuControl control;

public:
    Menu(std::string backgroundDir);
    Menu();

    ~Menu();

    int getSelectedButton();
    Managers::Control::MenuControl* getMenuControl();

    void selectUp();
    void selectDown();

    void addButton(Graphics::Button* button);

    void centerView();

    virtual void execute() = 0;
    
    void initializeSprite();
};

}