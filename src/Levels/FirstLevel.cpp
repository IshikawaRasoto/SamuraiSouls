#include "Levels/FirstLevel.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Obstacles/Barrel.hpp"
#include "Entities/Objects/Obstacles/Wagon.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"
#include "Entities/Objects/Props/HouseA.hpp"
#include "Entities/Objects/Props/HouseB.hpp"
#include "Entities/Objects/Props/HouseC.hpp"
#include "Entities/Objects/Props/StreetLamp.hpp"

#include "Levels/StructuresFactory.hpp"

#include "Data/Level.hpp"

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
    if(singlePlayer){
        viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    }else{
        if(player->getHP() > 0 && player2->getHP() > 0){
            viewPosition.x = (player->getPosition().x + player2->getPosition().x)/2;
        }else if(player->getHP() > 0){
            viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
        }else if(player2->getHP() > 0){
            viewPosition.x = player2->getPosition().x + WINDOW_SIZE_X/4;
        }
    }
    
    viewPosition.y = -WINDOW_SIZE_Y/2 + PAVEMENT_HEIGHT/2;
    
    graphicsManager->centerView(viewPosition);
    background.setPosition(viewPosition);
}

void FirstLevel::reset(){
    if(player){
        inputManager->unsubscribe("pressed", player->getPlayerControl());
        inputManager->unsubscribe("released", player->getPlayerControl());
    }
    
    if(player2){
        inputManager->unsubscribe("pressed", player2->getPlayerControl());
        inputManager->unsubscribe("released", player2->getPlayerControl());
    }

    for(int i = 0; i < entityList.getSize(); i++){
        if(entityList[i]) {
            delete entityList[i];
        }
    } 

    player = nullptr;
    player2 = nullptr;
    singlePlayer = true;

    entityList.clearAll();

    delete collisionManager.getMovingEntities();
    delete collisionManager.getStaticEntities();

    collisionManager.setMovingEntities(nullptr);
    collisionManager.setStaticEntities(nullptr);   

    hud.setPlayer1(nullptr);
    hud.setPlayer2(nullptr);

    Player::setPts(0);

    buildLevel();
}

void FirstLevel::update(float dt){
    showing = true;

    entityList.updateAll(dt);
    hud.update(dt);

    if(
        (!singlePlayer && player->getHP() <= 0 && player2->getHP() <= 0) ||
        (singlePlayer && player->getHP() <= 0) 
    ){
        changeCurrentState(Patterns::StateId::GameOver);
        showing = false;

        return;
    } 

    collisionManager.checkCollision();

    if(player->getFinishedLevel() || (player2 && player2->getFinishedLevel())){
        changeCurrentState(Patterns::StateId::MainMenu);
        reset();
    }
}

void FirstLevel::buildObjects(Lists::EntityList *movingEntities){
    std::vector<Entities::Entity*> structure;


    //Escada de caixas
    structure = 
        StructuresFactory<Obstacles::Box>::createStairs(2, {150.0f, -PAVEMENT_HEIGHT/2.f}, {BOX_WIDTH, BOX_HEIGHT});

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


    //Ground

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

    int stairsSize = rand()%6+2;

    if(rand()%2){
        structure = 
            StructuresFactory<Obstacles::Box>::createStairs(stairsSize, {900.0f, -PAVEMENT_HEIGHT/2}, {BOX_WIDTH, BOX_HEIGHT});
    }else{
        structure = 
            StructuresFactory<Obstacles::Barrel>::createStairs(stairsSize, {900.0f, -PAVEMENT_HEIGHT/2}, {BARREL_WIDTH, BARREL_HEIGHT});
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
    Enemies::Goblin *goblin = new Enemies::Goblin({400.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player, player2);
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

void FirstLevel::buildHouses(Lists::EntityList *staticEntities){
    Entities::Objects::Props::HouseA *houseA = new Entities::Objects::Props::HouseA({300.f, -PAVEMENT_HEIGHT/2.f - HOUSE_A_HEIGHT/2.f});
    staticEntities->addEntity(houseA);
    entityList.addEntity(houseA);

    Entities::Objects::Props::HouseB *houseB = new Entities::Objects::Props::HouseB({500.f, -PAVEMENT_HEIGHT/2.f - HOUSE_B_HEIGHT/2.f});
    staticEntities->addEntity(houseB);
    entityList.addEntity(houseB);

    houseA = new Entities::Objects::Props::HouseA({700.f, -PAVEMENT_HEIGHT/2.f - HOUSE_A_HEIGHT/2.f});
    staticEntities->addEntity(houseA);
    entityList.addEntity(houseA);

    Entities::Objects::Props::HouseC *houseC = new Entities::Objects::Props::HouseC({1450.f, -PAVEMENT_HEIGHT/2.f - HOUSE_C_HEIGHT/2.f});
    staticEntities->addEntity(houseC);
    entityList.addEntity(houseC);
    
    houseC = new Entities::Objects::Props::HouseC({1260.f, -PAVEMENT_HEIGHT/2.f - HOUSE_C_HEIGHT/2.f});
    staticEntities->addEntity(houseC);
    entityList.addEntity(houseC);

    houseB = new Entities::Objects::Props::HouseB({1700.f, -PAVEMENT_HEIGHT/2.f - HOUSE_B_HEIGHT/2.f});
    staticEntities->addEntity(houseB);
    entityList.addEntity(houseB);

    houseA = new Entities::Objects::Props::HouseA({1900.f, -PAVEMENT_HEIGHT/2.f - HOUSE_A_HEIGHT/2.f});
    staticEntities->addEntity(houseA);
    entityList.addEntity(houseA);

    houseC = new Entities::Objects::Props::HouseC({2100.f, -PAVEMENT_HEIGHT/2.f - HOUSE_C_HEIGHT/2.f});
    staticEntities->addEntity(houseC);
    entityList.addEntity(houseC);

    houseB = new Entities::Objects::Props::HouseB({2400.f, -PAVEMENT_HEIGHT/2.f - HOUSE_B_HEIGHT/2.f});
    staticEntities->addEntity(houseB);
    entityList.addEntity(houseB);


}

void FirstLevel::buildStreetLamps(Lists::EntityList *staticEntities){
     //STREETLAMPS

    Entities::Objects::Props::StreetLamp *streetLamp = nullptr;
    for(int i = -1; i < 7; i++){
        streetLamp= new Entities::Objects::Props::StreetLamp({500.f * (float)i + 250, -PAVEMENT_HEIGHT/2.f - STREET_LAMP_HEIGHT/2.f+7}); //7 é um ajuste manual par tridimensionalizar a rua (poste na extremidade da sprite)
        staticEntities->addEntity(streetLamp);
        entityList.addEntity(streetLamp);
    }

}

void FirstLevel::buildLevel(){
    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntities = new Lists::EntityList();

    //Altura é invertida no SFML.

    /*
        Como a origin de todos os sprites é igual a metade do tamanho dos mesmos, 
        é necessário sempre trabalhar com a metade do tamanho dos sprites na hora de posicioná-los
    */

    buildHouses(staticEntities);
    buildStaticEntities(staticEntities);
    buildObjects(movingEntities);

    Entities::Characters::Player *player = new Entities::Characters::Player({0.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, true);
    movingEntities->addEntity(player);
    entityList.addEntity(player);

    hud.setPlayer1(player);
    
    this->player = player;
    this->player2 = nullptr;

    
    buildCharacters(movingEntities);
    buildRandomEntities(staticEntities, movingEntities);
    buildStreetLamps(staticEntities);
    
    collisionManager.setMovingEntities(movingEntities);
    collisionManager.setStaticEntities(staticEntities);

    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl()); 

    if(player2){
        inputManager->subscribe("pressed", player2->getPlayerControl());
        inputManager->subscribe("released", player2->getPlayerControl());   
    }
}

void FirstLevel::load(){
    Lists::EntityList *movingEntities = Data::Level::loadSnapshots(id);

    if(!movingEntities){
        return;
    }

    if(player){
        inputManager->unsubscribe("pressed", player->getPlayerControl());
        inputManager->unsubscribe("released", player->getPlayerControl());
    }
    
    if(player2){
        inputManager->unsubscribe("pressed", player2->getPlayerControl());
        inputManager->unsubscribe("released", player2->getPlayerControl());
    }

    for(int i = 0; i < entityList.getSize(); i++){
        if(entityList[i]) {
            delete entityList[i];
        }
    } 

    player = nullptr;
    player2 = nullptr;

    entityList.clearAll();

    delete collisionManager.getMovingEntities();
    delete collisionManager.getStaticEntities();

    collisionManager.setStaticEntities(nullptr);   

    Lists::EntityList *staticEntities = new Lists::EntityList();

    buildStaticEntities(staticEntities);
    buildHouses(staticEntities);
    
    for(int i = 0; i < movingEntities->getSize(); i++){
        if((*movingEntities)[i]->getType() == Type::Player){
            Characters::Player* p = static_cast<Characters::Player*>((*movingEntities)[i]);

            if(p->getIsPlayerOne()){
                player = p;
            }else{
                player2 = p;
            }
        }
        entityList.addEntity((*movingEntities)[i]);
    }

    buildStreetLamps(staticEntities);

    hud.setPlayer1(player);
    hud.setPlayer2(player2);

    collisionManager.setMovingEntities(movingEntities);
    collisionManager.setStaticEntities(staticEntities);

    if(player){
        inputManager->subscribe("pressed", player->getPlayerControl());
        inputManager->subscribe("released", player->getPlayerControl());
    }
    
    if(player2){
        inputManager->subscribe("pressed", player2->getPlayerControl());
        inputManager->subscribe("released", player2->getPlayerControl());
    }
}

void FirstLevel::createPlayer2(){
    player2 = new Entities::Characters::Player({30.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, false);
    collisionManager.getMovingEntities()->addEntity(player2);
    entityList.addEntity(player2);

    hud.setPlayer2(player2);

    inputManager->subscribe("pressed", player2->getPlayerControl());
    inputManager->subscribe("released", player2->getPlayerControl());

    singlePlayer = false;

    for(int i = 0; i < entityList.getSize(); i++){
        Type entityType = entityList[i]->getType();

        if(entityType == Type::Goblin || entityType == Type::Boss || entityType == Type::Skeleton){
            (static_cast<Enemies::Enemy*>(entityList[i]))->setPlayer2(player2);
        }
    }
}

