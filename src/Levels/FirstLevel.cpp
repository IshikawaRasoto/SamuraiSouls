#include "Levels/FirstLevel.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"

using namespace Levels;

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
    movingEntities->addEntity(player);
    entityList.addEntity(player);
    
    Entities::Characters::Enemies::Goblin *goblin = new Entities::Characters::Enemies::Goblin({500.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    Entities::Characters::Enemies::Skeleton *skeleton = new Entities::Characters::Enemies::Skeleton({700.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);

    this->player = player;
        
    
    

    collisionManager = Managers::CollisionManager(movingEntities, staticEntites);

    
    

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