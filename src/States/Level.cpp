#include "States/Level.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Surfaces/Platform.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"

using namespace States;

Level::Level(
    Patterns::StateMachine *stateMachine,
    Managers::InputManager *inputManager, 
    Managers::GraphicsManager *graphicsManager
):
    State(Patterns::StateId::Play, stateMachine)
{
    this->inputManager = inputManager;
    this->graphicsManager = graphicsManager;

    Entities::Characters::Player *player = new Entities::Characters::Player({0.0f, LEVEL_Y-PLATFORM_HEIGHT*2});
    Entities::Objects::Obstacles::Box *box = new Entities::Objects::Obstacles::Box({50.0f, LEVEL_Y-PLATFORM_HEIGHT});
    Entities::Objects::Surfaces::Platform *platform = new Entities::Objects::Surfaces::Platform({0.0f,LEVEL_Y});
    Entities::Characters::Enemies::Goblin *goblin = new Entities::Characters::Enemies::Goblin({500.0f, LEVEL_Y-GOBLIN_HEIGHT-PLATFORM_HEIGHT},player);

    this->player = player;

    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntites = new Lists::EntityList();
        
    movingEntities->addEntity(player);
    movingEntities->addEntity(goblin);
    staticEntites->addEntity(box);
    staticEntites->addEntity(platform);

    collisionManager = Managers::CollisionManager(movingEntities, staticEntites);

    entityList.addEntity(player);
    entityList.addEntity(goblin);
    entityList.addEntity(box);
    entityList.addEntity(platform);

    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl());
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

    graphicsManager->centerView({player->getPosition().x, player->getPosition().y});

    render();
}

void Level::render(){
    graphicsManager->beginDraw();
    entityList.renderAll();
    graphicsManager->endDraw();
}

void Level::reset(){
    //TODO
}