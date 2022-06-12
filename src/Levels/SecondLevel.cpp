#include "Levels/SecondLevel.hpp"

#include "Entities/Objects/Obstacles/Gravestone.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Ground.hpp"
#include "Entities/Objects/Surfaces/MiniGround.hpp"
#include "Entities/Objects/Obstacles/Thorns.hpp"
#include "Entities/Objects/Obstacles/ThornsBase.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"
#include "Entities/Characters/Enemies/Boss.hpp"
#include "Entities/FireBall.hpp"


#include "Levels/StructuresFactory.hpp"

#include <vector>

using namespace Levels;
using namespace Entities::Objects;
using namespace Entities::Characters;

SecondLevel::SecondLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer):
    Level(stateMachine, SECOND_LEVEL_BACKGROUND_DIR, Patterns::StateId::SecondLevel, singlePlayer)
{
    srand(time(NULL));
    buildLevel();
    
    inputManager->subscribe("pressed", &control);
}

SecondLevel::~SecondLevel(){}

void SecondLevel::centerView(){
    sf::Vector2f viewPosition;
    viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    viewPosition.y = -WINDOW_SIZE_Y/2 + GROUND_HEIGHT/2;

    graphicsManager->centerView(viewPosition);
    // points.setPosition(viewPosition);
    // life.setPosition({viewPosition.x, viewPosition.y + 30});
    background.setPosition(viewPosition);
}

void SecondLevel::reset(){
    int i = 0;

    //A variável i evita tentar excluir duas vezes um player na entityList

    if(player){
        inputManager->unsubscribe("pressed", player->getPlayerControl());
        inputManager->unsubscribe("released", player->getPlayerControl());

        delete player;
        player = nullptr;
        i++;
    }
    
    if(player2){
        inputManager->unsubscribe("pressed", player2->getPlayerControl());
        inputManager->unsubscribe("released", player2->getPlayerControl());

        delete player2;
        player2 = nullptr;
        i++;
    }

    for(i; i < entityList.getSize(); i++){
        if(entityList[i]) {
            delete entityList[i];
        }
    }

    std::cout << "reset" << "\n";

    entityList.clearAll();

    hud.setPlayer1(nullptr);
    hud.setPlayer2(nullptr);


    buildLevel();
}

void SecondLevel::update(float dt){
    entityList.updateAll(dt);

    if(player->getHP() <= 0){
        changeCurrentState(Patterns::StateId::GameOver);
        showing = false;
        needReset = true;

        return;
    }

    collisionManager.checkCollision();
    hud.update(dt);
}   

void SecondLevel::buildFloor(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities){
    int i = 0, j = 0;

    std::vector<Entities::Entity*> structure;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(9, {-3*GROUND_WIDTH, 30}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 6;

    structure = StructuresFactory<Obstacles::ThornsBase>::createFloor(3, {GROUND_WIDTH*((float)i-1) + GROUND_WIDTH/2.f + THORNS_WIDTH*(float)j + THORNS_WIDTH/2.f, 30 + THORNSBASE_HEIGHT/2.f}, {THORNSBASE_WIDTH, THORNSBASE_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    structure = StructuresFactory<Obstacles::Thorns>::createFloor(3, {GROUND_WIDTH*((float)i-1) + GROUND_WIDTH/2.f + THORNS_WIDTH*(float)j + THORNS_WIDTH/2.f, 30 - THORNS_HEIGHT/2.f}, {THORNS_WIDTH, THORNS_HEIGHT});
    movingEntities->addEntity(structure);
    entityList.addEntity(structure);
    j += 3;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(3, {GROUND_WIDTH*(float)i + THORNS_WIDTH*(float)j, 30}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 3;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(3, {GROUND_WIDTH*(float)i + THORNS_WIDTH*(float)j, 0}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 3;

    if(rand()%2){
        structure = StructuresFactory<Obstacles::ThornsBase>::createFloor(3, {GROUND_WIDTH*(i-1) + GROUND_WIDTH/2.f + THORNS_WIDTH*j + THORNS_WIDTH/2.f, 30 + THORNSBASE_HEIGHT/2.f}, {THORNSBASE_WIDTH, THORNSBASE_HEIGHT});
        staticEntities->addEntity(structure);
        entityList.addEntity(structure);

        structure = StructuresFactory<Obstacles::Thorns>::createFloor(3, {GROUND_WIDTH*(i-1) + GROUND_WIDTH/2.f + THORNS_WIDTH*j + THORNS_WIDTH/2.f, 30 - THORNS_HEIGHT/2.f}, {THORNS_WIDTH, THORNS_HEIGHT});
        movingEntities->addEntity(structure);
        entityList.addEntity(structure);
    }else{
        structure = StructuresFactory<Surfaces::MiniGround>::createFloor(2, {GROUND_WIDTH*(i-1) + GROUND_WIDTH/2.f + THORNS_WIDTH*j + MINIGROUND_WIDTH/2.f, PAVEMENT_HEIGHT/2.f - MINIGROUND_HEIGHT/2.f}, {MINIGROUND_WIDTH, MINIGROUND_HEIGHT});
        staticEntities->addEntity(structure);
        entityList.addEntity(structure);
    }

    j+=2;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(4, {GROUND_WIDTH*(float)i + THORNS_WIDTH*(float)j, 0}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 4;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(11, {GROUND_WIDTH*(float)i + THORNS_WIDTH*(float)j, 80}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 11;
}

void SecondLevel::buildStaticEntities(Lists::EntityList *staticEntities){
    std::vector<Entities::Entity*> structure;

    structure = StructuresFactory<Surfaces::InvisibleBlock>::createWall(15, {-150.f, 60.f}, {BLOCK_WIDTH, BLOCK_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    structure = StructuresFactory<Surfaces::InvisibleBlock>::createWall(15, {4200.f, 100.f}, {BLOCK_WIDTH, BLOCK_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
}


void SecondLevel::buildObjects(Lists::EntityList *movingEntities){

    Entities::Objects::Obstacles::Gravestone *grave = new Entities::Objects::Obstacles::Gravestone({100.f, 30-GROUND_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({200.f, 30-GROUND_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({700.f, 30-GROUND_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({1200.f, 30-GROUND_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({1900.f, -GROUND_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);
}
void SecondLevel::buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities){
    
    int i = 0, n = (rand()%2) + 1;

    Entities::Characters::Enemies::Skeleton *skeleton = nullptr;
    for(i; i<n; i++){
        skeleton = new Entities::Characters::Enemies::Skeleton({1500.f + 150.f*(float)i, 30-GROUND_HEIGHT/2.f}, player, player2);
        movingEntities->addEntity(skeleton);
        entityList.addEntity(skeleton);
    }

    Entities::Objects::Obstacles::Gravestone *grave = nullptr;
        
    for(i = 0; i < 8; i++){
        if(rand()%2){
            grave = new Entities::Objects::Obstacles::Gravestone({1600.f + (float) i * 300.f, -GROUND_HEIGHT/2.f});
            movingEntities->addEntity(grave);
            entityList.addEntity(grave);
        }else{
            skeleton = new Entities::Characters::Enemies::Skeleton({1600.f + 300.f*(float)i, -GROUND_HEIGHT/2.f}, player, player2);
            movingEntities->addEntity(skeleton);
            entityList.addEntity(skeleton);
        }
    }
    
}
void SecondLevel::buildCharacters(Lists::EntityList *movingEntities){
    Entities::Characters::Enemies::Skeleton *skeleton = new Entities::Characters::Enemies::Skeleton({400.f, 30-GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);

    skeleton = new Entities::Characters::Enemies::Skeleton({600.f, 30-GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);

    skeleton = new Entities::Characters::Enemies::Skeleton({1000.f, 30-GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);

    Entities::FireBall *fireball = new Entities::FireBall({4000.f, 80-GROUND_HEIGHT/2.f});
    movingEntities->addEntity(fireball);
    entityList.addEntity(fireball);

    Entities::Characters::Enemies::Boss *boss = new Entities::Characters::Enemies::Boss({4000.f, 80-GROUND_HEIGHT/2.f}, fireball, player, player2);
    movingEntities->addEntity(boss);
    entityList.addEntity(boss);
}

void SecondLevel::buildLevel(){

    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntities = new Lists::EntityList();
    
    srand(time(NULL));

    //Altura é invertida no SFML.

    /*
        Como a origin de todos os sprites é igual a metade do tamanho dos mesmos, 
        é necessário sempre trabalhar com a metade do tamanho dos sprites na hora de posicioná-los
    */

    Entities::Characters::Player *player = new Entities::Characters::Player({0.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, true);
    movingEntities->addEntity(player);
    entityList.addEntity(player);

    hud.setPlayer1(player);

    Entities::Characters::Player *player2 = nullptr;
    if(!singlePlayer){
        player2 = new Entities::Characters::Player({50.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, false);
        movingEntities->addEntity(player2);
        entityList.addEntity(player2);

        hud.setPlayer2(player2);
    }
    
    this->player = player;
    this->player2 = player2;

    buildStaticEntities(staticEntities);
    buildFloor(staticEntities, movingEntities);
    buildObjects(movingEntities);
    buildCharacters(movingEntities);
    buildRandomEntities(staticEntities, movingEntities);
        
    collisionManager.setMovingEntities(movingEntities);
    collisionManager.setStaticEntities(staticEntities);

    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl()); 

    if(player2){
        inputManager->subscribe("pressed", player2->getPlayerControl());
        inputManager->subscribe("released", player2->getPlayerControl());   
    }
}