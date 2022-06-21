#pragma once

#include "Text.hpp"
#include "Ent/Ent.hpp"
#include "Entities/Characters/Player.hpp"
#include "Managers/Graphics.hpp"

#define HUD_FONT_DIR "./fonts/SpecialElite.ttf"
#define HUD_FONT_COLOR sf::Color::White

namespace Graphics{

class Hud : public Ent{
private:
    Graphics::Text player1HP;
    Graphics::Text player2HP;

    Graphics::Text points;

    Entities::Characters::Player *player1;
    Entities::Characters::Player *player2;

    static Managers::GraphicsManager *graphicsManager;
public:

    Hud(Entities::Characters::Player *player1 = nullptr, Entities::Characters::Player *player2 = nullptr);
    ~Hud();

    void setPlayer1(Entities::Characters::Player *player);
    void setPlayer2(Entities::Characters::Player *player);

    void update(const float dt);
    void render();

    void initializeSprite();
};

};