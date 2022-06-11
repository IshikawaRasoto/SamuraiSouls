#include "Levels/Level.hpp"

using namespace Levels;

Level::Level(
    Patterns::StateMachine *stateMachine,
    std::string backgroundDir,
    Patterns::StateId state,
    const bool singlePlayer,
    Managers::InputManager *inputManager,
    Managers::GraphicsManager *graphicsManager
):
    State(state, stateMachine),
    background(backgroundDir),
    singlePlayer(singlePlayer),
    control(this),
    hud()
{
    this->inputManager = inputManager;
    this->graphicsManager = graphicsManager;
}

Level::~Level(){
    for(int i = 0; i < entityList.getSize(); i++){
        if(entityList[i]) delete entityList[i];
    }

    graphicsManager = nullptr;
    inputManager = nullptr;
}

void Level::handlePause(){
    changeCurrentState(Patterns::StateId::Pause);
}

void Level::update(float dt){
    entityList.updateAll(dt);
    collisionManager.checkCollision();
    render();
}

void Level::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();
    hud.render();
    entityList.renderAll();
    graphicsManager->endDraw();
}


