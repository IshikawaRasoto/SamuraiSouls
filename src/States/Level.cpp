#include "States/Level.hpp"

using namespace States;

Level::Level(
    Patterns::StateMachine *stateMachine,
    std::string backgroundDir,
    Patterns::StateId state,
    Managers::InputManager *inputManager,
    Managers::GraphicsManager *graphicsManager
):
    State(state, stateMachine),
    background(backgroundDir)
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

void Level::update(float dt){
    entityList.updateAll(dt);
    collisionManager.checkCollision();
    render();
}

void Level::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();
    entityList.renderAll();
    graphicsManager->endDraw();
}

