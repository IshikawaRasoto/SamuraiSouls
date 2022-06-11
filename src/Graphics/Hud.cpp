#include "Graphics/Hud.hpp"
#include "Type.hpp"

using namespace Graphics;

Managers::GraphicsManager* Hud::graphicsManager = GraphicsManager::getInstance();

Hud::Hud(
    Entities::Characters::Player *player1, 
    Entities::Characters::Player *player2
):
    Ent(Type::Hud, {0.0f, 0.0f}, {0.0f, 0.0f}),
    player1HP("",{0.0f,0.0f}, HUD_FONT_DIR),
    player2HP("",{0.0f,0.0f}, HUD_FONT_DIR),
    points("",{0.0f,0.0f}, HUD_FONT_DIR)
{
    this->player1 = player1;
    this->player2 = player2;

    player1HP.setColor(HUD_FONT_COLOR);
    player2HP.setColor(HUD_FONT_COLOR);
    points.setColor(HUD_FONT_COLOR);
}

Hud::~Hud(){}

void Hud::setPlayer1(Entities::Characters::Player *player){
    player1 = player;
}

void Hud::setPlayer2(Entities::Characters::Player *player){
    player2 = player;
}

void Hud::update(const float dt){
    if(!player1) return;

    position = graphicsManager->getTopLeftPosition();

    int p1HP = 0, p2HP = 0;

    p1HP = player1->getHP();

    if(player2){
        p2HP = player2->getHP();
    }

    player1HP.setValue("Player 1 - HP: " + std::to_string(p1HP));
    player2HP.setValue("Player 2 - HP: " + std::to_string(p2HP));
    points.setValue("Points: " + std::to_string(player1->getPts()));

    player1HP.setPosition({
        position.x + 20.0f,
        position.y + 20.0f
    });

    player2HP.setPosition({
        position.x + 20.0f, 
        position.y + player1HP.getSize().y + 20.0f
    });

    points.setPosition({
        position.x + graphicsManager->getSize().x - points.getSize().x - 20.0f, 
        position.y + 20.0f
    });
}

void Hud::render(){
    if(!player1) return;

    points.render();
    player1HP.render();

    if(player2){
        player2HP.render();
    }
}

void Hud::initializeSprite(){}