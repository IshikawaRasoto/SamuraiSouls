#include "Menus/YouWin.hpp"

#include "Graphics/Button.hpp"
#include "Managers/Keyboard.hpp"

#include "Data/Leaderboard.hpp"
#include "Entities/Characters/Player.hpp"

using namespace Menus;

YouWin::YouWin(StateMachine *stateMachine):
    State(StateId::YouWin,stateMachine),
    Menu(YOUWIN_BACKGROUND_DIR),
    title("You win!", {0.0f, 0.0f}, YOUWIN_TITLE_FONT_DIR),
    typeYourName("Type your name:", {0.0f, 80.0f}, YOUWIN_TITLE_FONT_DIR),
    leaderboardName("", {0.0f, typeYourName.getSize().y + 100.0f}, YOUWIN_TITLE_FONT_DIR)
{

    title.setFontSize(YOUWIN_TITLE_START_SIZE);
    typeYourName.setFontSize(15);
    leaderboardName.setFontSize(35);
    
    title.setColor(sf::Color::Yellow);
    typeYourName.setColor(sf::Color::White);
    leaderboardName.setColor(sf::Color::White);

    title.setTextAlignment(Graphics::TextAlignment::Center);
    typeYourName.setTextAlignment(Graphics::TextAlignment::Center);
    leaderboardName.setTextAlignment(Graphics::TextAlignment::Center);

    addButton(new Graphics::Button("Back", {0.0f, 200.0f}, YOUWIN_TITLE_FONT_DIR));
    control.setMenuHasInput(true);
}

YouWin::~YouWin(){}

void YouWin::execute(){
    if(!getIsShowing()) return;

    //Enquanto o usuário não digitar o nome da leaderboard, não é possível retornar ao menu.
    if(name.length() == 0) return;

    saveName();
    changeCurrentState(Patterns::StateId::MainMenu);

    reset();
    setIsShowing(false);
}

void YouWin::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();

    for(auto button : buttons){
        button->render();
    }

    title.render();
    typeYourName.render();
    leaderboardName.render();
    graphicsManager->endDraw();
}

void YouWin::update(const float dt){
    setIsShowing(true);

    if(title.getFontSize() < YOUWIN_TITLE_MAX_SIZE){
        title.setFontSize(title.getFontSize() + 1);
    }

    leaderboardName.setValue(name);
}

void YouWin::reset(){
    title.setFontSize(YOUWIN_TITLE_START_SIZE);
    name.clear();
    leaderboardName.setValue("");
}

void YouWin::saveName(){
    Data::Leaderboard::saveName(name, Entities::Characters::Player::getPts());
}

void YouWin::handleInput(std::string key){
    if(!getIsShowing()) return;

    if(key == "Backspace" && name.length()){
        name.pop_back();
        return;
    }

    if(name.length() > YOUWIN_LEADERBOARDNAME_MAX_LENGTH) return;

    if(Keyboard::Text.find(key) != Keyboard::Text.end()){
        name += Keyboard::Text[key];
    }
}