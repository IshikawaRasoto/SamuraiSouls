#include "Levels/Level.hpp"

#include "Snapshots/LevelSnapshot.hpp"
#include "Data/Level.hpp"

using namespace Levels;

Levels::Level* Level::currentLevel = nullptr;

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

Levels::Level* Level::getCurrentLevel(){
    return currentLevel;
}

void Level::setCurrentLevel(Levels::Level *level){
    currentLevel = level;
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

void Level::save(){
    std::vector<Snapshots::EntitySnapshot*> snapshots;
    Lists::EntityList *movingEntities = collisionManager.getMovingEntities();

    for(int i = 0; i < movingEntities->getSize(); i++){
        if((*movingEntities)[i]->getIsShowing()){
            snapshots.push_back((*movingEntities)[i]->save());
        }
    }

    Snapshots::LevelSnapshot *levelSnapshot = new Snapshots::LevelSnapshot(
        id,
        Entities::Characters::Player::getPts()
    );

    Data::Level::saveSnapshots(snapshots, levelSnapshot);

    delete levelSnapshot;

    for(auto snapshot : snapshots){
        delete snapshot;
    }
}

void Level::load(){}

