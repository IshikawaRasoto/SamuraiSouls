#include "States/Level.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"

using namespace States;

Level::Level(
    Patterns::StateMachine *stateMachine,
    Managers::InputManager *inputManager, 
    Managers::GraphicsManager *graphicsManager
):
    State(Patterns::StateId::Play, stateMachine),
    background(LEVEL_BACKGROUND_DIR)
{
    this->inputManager = inputManager;
    this->graphicsManager = graphicsManager;

    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntites = new Lists::EntityList();

    //Altura é invertida no SFML.

    /*
        Como a origin de todos os sprites é igual a metade do tamanho dos mesmos, 
        é necessário sempre trabalhar com a metade do tamanho dos sprites na hora de posicioná-los
    */

    for(int i = 0; i < 5; i++){
       Entities::Objects::Surfaces::Pavement *pavement = new Entities::Objects::Surfaces::Pavement({float(i)*PAVEMENT_WIDTH, 0});
       staticEntites->addEntity(pavement);
       entityList.addEntity(pavement);
    }

    Entities::Characters::Player *player = new Entities::Characters::Player({0.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2});
    Entities::Objects::Obstacles::Box *box = new Entities::Objects::Obstacles::Box({50.0f, -PAVEMENT_HEIGHT/2-BOX_HEIGHT/2});
    Entities::Characters::Enemies::Goblin *goblin = new Entities::Characters::Enemies::Goblin({500.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);

    this->player = player;
        
    movingEntities->addEntity(player);
    movingEntities->addEntity(goblin);
    staticEntites->addEntity(box);

    collisionManager = Managers::CollisionManager(movingEntities, staticEntites);

    entityList.addEntity(player);
    entityList.addEntity(goblin);
    entityList.addEntity(box);

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

    centerView();
    render();
}

void Level::centerView(){
    sf::Vector2f viewPosition;
    viewPosition.x = player->getPosition().x;
    viewPosition.y = -WINDOW_SIZE_Y/2 + PAVEMENT_HEIGHT/2;

    graphicsManager->centerView(viewPosition);
    background.setPosition(viewPosition);
}

void Level::render(){
    graphicsManager->beginDraw();
    background.render();
    entityList.renderAll();
    graphicsManager->endDraw();
}

void Level::reset(){
    //TODO
}