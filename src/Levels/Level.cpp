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
    showing = false;

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

bool Level::getShowing(){
    return showing;
}

void Level::setShowing(bool showing){
    this->showing = showing;
}

void Level::handlePause(){
    if(!showing) return;

    changeCurrentState(Patterns::StateId::Pause);

    showing = false;
}

void Level::update(float dt){
    showing = true;

    entityList.updateAll(dt);
    collisionManager.checkCollision();
}

void Level::render(){
    graphicsManager->beginDraw();
    centerView();
    background.render();
    hud.render();
    entityList.renderAll();
    graphicsManager->endDraw();
}


