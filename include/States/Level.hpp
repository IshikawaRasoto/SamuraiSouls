#pragma once

#include "Managers/Collision.hpp"
#include "Managers/Input.hpp"
#include "Managers/Graphics.hpp"
#include "Lists/EntityList.hpp"

#include "Entities/Characters/Player.hpp"
#include "Patterns/State.hpp"

#include "Graphics/Background.hpp"

#define LEVEL_Y 0
#define LEVEL_BACKGROUND_DIR "./Textures/Scenario/Village/VillageBackGround.png"

namespace States{

class Level : public Patterns::State{
protected:
    Managers::CollisionManager collisionManager;
    Managers::InputManager *inputManager;
    Managers::GraphicsManager *graphicsManager;
    Lists::EntityList entityList;
    Entities::Characters::Player *player;
    Graphics::Background background;

public:
    Level(
        Patterns::StateMachine *stateMachine,
        Managers::InputManager *inputManager = Managers::InputManager::getInstance(), 
        Managers::GraphicsManager *graphicsManager = Managers::GraphicsManager::getInstance()
    );
    ~Level();

    virtual void update(float dt) = 0;
    void render();
    void reset();

    virtual void centerView();
};

}

