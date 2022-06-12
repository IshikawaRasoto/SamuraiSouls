#include "Levels/FirstLevel.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Obstacles/Barrel.hpp"
#include "Entities/Objects/Obstacles/Wagon.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"

#include "Levels/StructuresFactory.hpp"

#include <vector>

using namespace Levels;
using namespace Entities::Objects;
using namespace Entities::Characters;

FirstLevel::FirstLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer):
    Level(stateMachine, FIRST_LEVEL_BACKGROUND_DIR, Patterns::StateId::FirstLevel, singlePlayer)
{
    srand(time(NULL));
    buildLevel();

    inputManager->subscribe("pressed", &control);
}

FirstLevel::~FirstLevel(){}

void FirstLevel::centerView(){
    if(!player) return;

    sf::Vector2f viewPosition;

    if(singlePlayer)
        viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    else
        viewPosition.x = (player->getPosition().x + player2->getPosition().x)/2;
    
    viewPosition.y = -WINDOW_SIZE_Y/2 + PAVEMENT_HEIGHT/2;
    
    graphicsManager->centerView(viewPosition);
    background.setPosition(viewPosition);
}

void FirstLevel::reset(){
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

    entityList.clearAll();

    hud.setPlayer1(nullptr);
    hud.setPlayer2(nullptr);

    buildLevel();
}

void FirstLevel::update(float dt){
    showing = true;

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

void FirstLevel::buildObjects(Lists::EntityList *movingEntities){
    std::vector<Entities::Entity*> structure;

    //Escada de caixas
    structure = 
        StructuresFactory<Obstacles::Box>::createStairs(2, {150.0f, -PAVEMENT_HEIGHT/2.0f}, {BOX_WIDTH, BOX_HEIGHT});

    movingEntities->addEntity(structure);
    entityList.addEntity(structure);

    structure = 
        StructuresFactory<Obstacles::Barrel>::createWall(2,{1575.0f, -PAVEMENT_HEIGHT/2.f}, {BARREL_WIDTH, BARREL_HEIGHT});

    movingEntities->addEntity(structure);
    entityList.addEntity(structure);

    Entities::Objects::Obstacles::Barrel *barrel = new Obstacles::Barrel({50.f, -PAVEMENT_HEIGHT/2.f - BARREL_HEIGHT/2.f});
    movingEntities->addEntity(barrel);
    entityList.addEntity(barrel);

    Entities::Objects::Obstacles::Wagon *wagon = new Obstacles::Wagon({2300.f, -PAVEMENT_HEIGHT/2.f - WAGON_HEIGHT/2.f});
    movingEntities->addEntity(wagon);
    entityList.addEntity(wagon);
}

void FirstLevel::buildStaticEntities(Lists::EntityList *staticEntities){
    std::vector<Entities::Entity*> structure;

    structure = 
        StructuresFactory<Surfaces::Pavement>::createFloor(32, {PAVEMENT_WIDTH * -2, 0}, {PAVEMENT_WIDTH, PAVEMENT_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    //Parede de blocos invisíveis para impedir a passagem do player para os extremos do nível. 
    structure = 
        StructuresFactory<Surfaces::InvisibleBlock>::createWall(10,{-150.0f, 0.f}, {BLOCK_WIDTH, BLOCK_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    structure = 
        StructuresFactory<Surfaces::InvisibleBlock>::createWall(10,{2400.0f, 0.f}, {BLOCK_WIDTH, BLOCK_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
}

void FirstLevel::buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities){
    std::vector<Entities::Entity*> structure;
    Entities::Entity *entity;

    /*
        Aqui temos 50% de chance de ser criado uma escada de caixas e 50% de chance de ser criado uma caixa
        de barris. Além disso, cada escada também tem seu tamanho definido aleatoriamente.
    */

    int stairsSize = rand()%10+1;

    if(rand()%2){
        structure = 
            StructuresFactory<Obstacles::Box>::createStairs(stairsSize, {1000.0f, -PAVEMENT_HEIGHT/2}, {BOX_WIDTH, BOX_HEIGHT});
    }else{
        structure = 
            StructuresFactory<Obstacles::Barrel>::createStairs(stairsSize, {1000.0f, -PAVEMENT_HEIGHT/2}, {BARREL_WIDTH, BARREL_HEIGHT});
    }

    movingEntities->addEntity(structure);
    entityList.addEntity(structure);

    /*
        Aqui temos 50% de chance de ser criado um goblin e 50% de chance de ser criado uma caixa.
    */

    if(rand()%2){
        entity = new Enemies::Goblin({2000.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2}, player, player2);
    }else{
        entity = new Obstacles::Barrel({2000.f, -PAVEMENT_HEIGHT/2.f - BARREL_HEIGHT/2.f});
    }

    movingEntities->addEntity(entity);
    entityList.addEntity(entity);
}

void FirstLevel::buildCharacters(Lists::EntityList *movingEntities){
    Enemies::Goblin *goblin = new Enemies::Goblin({250.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player, player2);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    Enemies::Skeleton *skeleton = new Enemies::Skeleton({700.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);

    goblin = new Enemies::Goblin({1400.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player, player2);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    goblin = new Enemies::Goblin({1500.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player, player2);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    skeleton = new Enemies::Skeleton({1650.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);    

    skeleton = new Entities::Characters::Enemies::Skeleton({2200.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);  
}

void FirstLevel::buildLevel(){
    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntities = new Lists::EntityList();

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