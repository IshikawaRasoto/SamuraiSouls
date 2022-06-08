#include "States/FirstLevel.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"

using namespace States;

FirstLevel::FirstLevel(Patterns::StateMachine* stateMachine):
    Level(stateMachine, FIRST_LEVEL_BACKGROUND_DIR, Patterns::StateId::FirstLevel)
{
    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntites = new Lists::EntityList();

    //Altura é invertida no SFML.

    /*
        Como a origin de todos os sprites é igual a metade do tamanho dos mesmos, 
        é necessário sempre trabalhar com a metade do tamanho dos sprites na hora de posicioná-los
    */

    for(int i = -2; i < 10; i++){
        Entities::Objects::Surfaces::Pavement *pavement = new Entities::Objects::Surfaces::Pavement({float(i)*PAVEMENT_WIDTH, 0});
        staticEntites->addEntity(pavement);
        entityList.addEntity(pavement);
    }

    for(int i = 0; i < 3; i++){
        Entities::Objects::Obstacles::Box *box = new Entities::Objects::Obstacles::Box({50.0f+i*BOX_WIDTH, -PAVEMENT_HEIGHT/2 - BOX_HEIGHT/2});
        staticEntites->addEntity(box);
        entityList.addEntity(box);
    }

    for(int i = 1; i <= 2; i++){
        Entities::Objects::Obstacles::Box *box = new Entities::Objects::Obstacles::Box({50.0f+i*BOX_WIDTH, -PAVEMENT_HEIGHT/2 - (BOX_HEIGHT+BOX_HEIGHT/2)});
        staticEntites->addEntity(box);
        entityList.addEntity(box);
    }

    Entities::Objects::Obstacles::Box *box = new Entities::Objects::Obstacles::Box({50.0f+BOX_WIDTH*2, - PAVEMENT_HEIGHT/2 - (BOX_HEIGHT*2+BOX_HEIGHT/2)});
    staticEntites->addEntity(box);
    entityList.addEntity(box);


    Entities::Characters::Player *player = new Entities::Characters::Player({0.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2});
    Entities::Characters::Enemies::Goblin *goblin = new Entities::Characters::Enemies::Goblin({500.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);

    this->player = player;
        
    movingEntities->addEntity(player);
    movingEntities->addEntity(goblin);

    collisionManager = Managers::CollisionManager(movingEntities, staticEntites);

    entityList.addEntity(player);
    entityList.addEntity(goblin);

    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl());      
    
}

FirstLevel::~FirstLevel(){}

void FirstLevel::centerView(){
    sf::Vector2f viewPosition;
    viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    viewPosition.y = -WINDOW_SIZE_Y/2 + PAVEMENT_HEIGHT/2;

    graphicsManager->centerView(viewPosition);
    background.setPosition(viewPosition);
}

void FirstLevel::reset(){
    //TODO
}