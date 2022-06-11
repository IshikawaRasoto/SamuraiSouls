#pragma once

#include "Managers/Collision.hpp"
#include "Managers/Input.hpp"
#include "Managers/Graphics.hpp"
#include "Managers/Control/LevelControl.hpp"

#include "Lists/EntityList.hpp"

#include "Entities/Characters/Player.hpp"
#include "Patterns/State.hpp"

#include "Graphics/Background.hpp"

#include <time.h>
#include <string>

#define LEVEL_Y 0

namespace Levels{

class Level : public Patterns::State{
protected:
    Managers::CollisionManager collisionManager;
    Managers::InputManager *inputManager;
    Managers::GraphicsManager *graphicsManager;
    Managers::Control::LevelControl control;

    Lists::EntityList entityList;
    Entities::Characters::Player *player;
    Entities::Characters::Player *player2;
    Graphics::Background background;
    bool singlePlayer;

public:
    Level(
        Patterns::StateMachine *stateMachine,
        std::string backgroundDir,
        Patterns::StateId state,
        const bool singlePlayer,
        Managers::InputManager *inputManager = Managers::InputManager::getInstance(), 
        Managers::GraphicsManager *graphicsManager = Managers::GraphicsManager::getInstance()
        
    );
    virtual ~Level();

    void handlePause();

    virtual void update(float dt);
    void render();

    virtual void reset() = 0; 
    virtual void centerView() = 0;
};

}

