#pragma once

#include <vector>
#include <string>
#include "Graphics/Button.hpp"
#include "Graphics/Background.hpp"

#include "Managers/Graphics.hpp"

namespace Menus{

class Menu : public Ent{
protected:
    std::vector<Graphics::Button*> buttons;
    int buttonSelected;
    Graphics::Background background;

    static Managers::GraphicsManager* graphicsManager;

    //Control::MenuControl control;

public:
    Menu(std::string backgroundDir);
    Menu();
    ~Menu();

    int getButtonSelected();
    //Control::MenuControl getMenuControl();

    void selectUp();
    void selectDown();

    void addButton(Graphics::Button* button);

    void centerView();

    virtual void execute() = 0;

    void initializeSprite();
};

}