#include "Levels/SecondLevel.hpp"

#include "Entities/Objects/Obstacles/Gravestone.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Ground.hpp"
#include "Entities/Objects/Surfaces/MiniGround.hpp"
#include "Entities/Objects/Obstacles/Thorns.hpp"
#include "Entities/Objects/Obstacles/ThornsBase.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Boss.hpp"
#include "Entities/FireBall.hpp"
#include "Entities/Objects/Props/Bush.hpp"
#include "Entities/Objects/Props/Statue.hpp"
#include "Entities/Objects/Props/TreeA.hpp"
#include "Entities/Objects/Props/TreeB.hpp"

#include "Levels/StructuresFactory.hpp"

#include "Data/Level.hpp"

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


    viewPosition.y = -WINDOW_SIZE_Y/2 + GROUND_HEIGHT/2;

    graphicsManager->centerView(viewPosition);
    background.setPosition(viewPosition);
}

void SecondLevel::reset(){
    int i = 0;

    //A variável i evita tentar excluir duas vezes um player na entityList

    if(player){
        inputManager->unsubscribe("pressed", player->getPlayerControl());
        inputManager->unsubscribe("released", player->getPlayerControl());
    }
    
    if(player2){
        inputManager->unsubscribe("pressed", player2->getPlayerControl());
        inputManager->unsubscribe("released", player2->getPlayerControl());
    }

    for(i = 0; i < entityList.getSize(); i++){
        if(entityList[i]) {
            delete entityList[i];
        }
    }

    player = nullptr;
    player2 = nullptr;
    singlePlayer = true;

    entityList.clearAll();

    hud.setPlayer1(nullptr);
    hud.setPlayer2(nullptr);

    Player::setPts(0);

    buildLevel();
}

void SecondLevel::update(float dt){
    showing = true;

    entityList.updateAll(dt);

    if(
        (!singlePlayer && player->getHP() <= 0 && player2->getHP() <= 0) ||
        (singlePlayer && player->getHP() <= 0) 
    ){
        changeCurrentState(Patterns::StateId::GameOver);
        showing = false;

        return;
    } 

    collisionManager.checkCollision();
    hud.update(dt);
}   

void SecondLevel::buildFloor(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities){
    int i = 0;

    std::vector<Entities::Entity*> structure;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(9, {-3*GROUND_WIDTH, 30}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 6;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(3, {GROUND_WIDTH*(float)i, 30}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 3;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(3, {GROUND_WIDTH*(float)i, 0}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 3;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(4, {GROUND_WIDTH*(float)i , 0}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 4;

    structure = StructuresFactory<Surfaces::Ground>::createFloor(11, {GROUND_WIDTH*(float)i , 80}, {GROUND_WIDTH, GROUND_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
    i += 11;
}

void SecondLevel::buildStaticEntities(Lists::EntityList *staticEntities){
    std::vector<Entities::Entity*> structure;

    Entities::Objects::Props::Statue *statue = new Entities::Objects::Props::Statue({15.f, 30-GROUND_HEIGHT/2.f-STATUE_HEIGHT/2.f});
    staticEntities->addEntity(statue);
    entityList.addEntity(statue);

    Entities::Objects::Props::Bush *bush = new Entities::Objects::Props::Bush({-130.f, 45-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({300.f, 45-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    Entities::Objects::Props::TreeA *treeA = new Entities::Objects::Props::TreeA({500.f, 30-GROUND_HEIGHT/2.f-TREE_A_HEIGHT/2.f});
    staticEntities->addEntity(treeA);
    entityList.addEntity(treeA);

    Entities::Objects::Props::TreeB *treeB = new Entities::Objects::Props::TreeB({900.f, 30-GROUND_HEIGHT/2.f-TREE_B_HEIGHT/2.f});
    staticEntities->addEntity(treeB);
    entityList.addEntity(treeB);

    bush = new Entities::Objects::Props::Bush({840.f, 45-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({1300.f, 45-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeB = new Entities::Objects::Props::TreeB({1600.f, 30-GROUND_HEIGHT/2.f-TREE_B_HEIGHT/2.f});
    staticEntities->addEntity(treeB);
    entityList.addEntity(treeB);

    bush = new Entities::Objects::Props::Bush({1900.f, 15-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeA = new Entities::Objects::Props::TreeA({2100.f, -GROUND_HEIGHT/2.f-TREE_A_HEIGHT/2.f});
    staticEntities->addEntity(treeA);
    entityList.addEntity(treeA);

    bush = new Entities::Objects::Props::Bush({2200.f, 15-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({2500.f, 15-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeB = new Entities::Objects::Props::TreeB({2600.f, -GROUND_HEIGHT/2.f-TREE_B_HEIGHT/2.f});
    staticEntities->addEntity(treeB);
    entityList.addEntity(treeB);

    bush = new Entities::Objects::Props::Bush({2800.f, 15-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    statue = new Entities::Objects::Props::Statue({2950.f, -GROUND_HEIGHT/2.f-STATUE_HEIGHT/2.f});
    staticEntities->addEntity(statue);
    entityList.addEntity(statue);

    treeB = new Entities::Objects::Props::TreeB({3300.f, 80-GROUND_HEIGHT/2.f-TREE_B_HEIGHT/2.f});
    staticEntities->addEntity(treeB);
    entityList.addEntity(treeB);

    bush = new Entities::Objects::Props::Bush({3400.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeA = new Entities::Objects::Props::TreeA({3500.f, 80-GROUND_HEIGHT/2.f-TREE_A_HEIGHT/2.f});
    staticEntities->addEntity(treeA);
    entityList.addEntity(treeA);

    bush = new Entities::Objects::Props::Bush({3600.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({3720.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeA = new Entities::Objects::Props::TreeA({3800.f, 80-GROUND_HEIGHT/2.f-TREE_A_HEIGHT/2.f});
    staticEntities->addEntity(treeA);
    entityList.addEntity(treeA);

    bush = new Entities::Objects::Props::Bush({3900.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({4025.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeB = new Entities::Objects::Props::TreeB({4100.f, 80-GROUND_HEIGHT/2.f-TREE_B_HEIGHT/2.f});
    staticEntities->addEntity(treeB);
    entityList.addEntity(treeB);

    bush = new Entities::Objects::Props::Bush({4200.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({4400.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({4325.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({4500.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeB = new Entities::Objects::Props::TreeB({4600.f, 80-GROUND_HEIGHT/2.f-TREE_B_HEIGHT/2.f});
    staticEntities->addEntity(treeB);
    entityList.addEntity(treeB);

    bush = new Entities::Objects::Props::Bush({4750.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    bush = new Entities::Objects::Props::Bush({4875.f, 95-GROUND_HEIGHT/2.f-BUSH_HEIGHT/2.f});
    staticEntities->addEntity(bush);
    entityList.addEntity(bush);

    treeA = new Entities::Objects::Props::TreeA({5000.f, 80-GROUND_HEIGHT/2.f-TREE_A_HEIGHT/2.f});
    staticEntities->addEntity(treeA);
    entityList.addEntity(treeA);

    //Invisible Walls

    structure = StructuresFactory<Surfaces::InvisibleBlock>::createWall(15, {-250.f, 60.f}, {BLOCK_WIDTH, BLOCK_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    structure = StructuresFactory<Surfaces::InvisibleBlock>::createWall(15, {4200.f, 100.f}, {BLOCK_WIDTH, BLOCK_HEIGHT});
    staticEntities->addEntity(structure);
    entityList.addEntity(structure);
}

void SecondLevel::buildStatues(Lists::EntityList *staticEntities){
    Entities::Objects::Props::Statue *statue = new Entities::Objects::Props::Statue({30.f, 40-GROUND_HEIGHT/2.f-STATUE_HEIGHT/2.f});
    staticEntities->addEntity(statue);
    entityList.addEntity(statue);

    statue = new Entities::Objects::Props::Statue({1800.f, 10-GROUND_HEIGHT/2.f-STATUE_HEIGHT/2.f});
    staticEntities->addEntity(statue);
    entityList.addEntity(statue);

    statue = new Entities::Objects::Props::Statue({2965.f, 10-GROUND_HEIGHT/2.f-STATUE_HEIGHT/2.f});
    staticEntities->addEntity(statue);
    entityList.addEntity(statue);

}


void SecondLevel::buildObjects(Lists::EntityList *movingEntities){

    std::vector<Entities::Entity*> structure;

    Entities::Objects::Obstacles::Gravestone *grave = new Entities::Objects::Obstacles::Gravestone({100.f, 30-GROUND_HEIGHT/2.f-GRAVESTONE_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({200.f, 30-GROUND_HEIGHT/2.f-GRAVESTONE_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({700.f, 30-GROUND_HEIGHT/2.f-GRAVESTONE_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    grave = new Entities::Objects::Obstacles::Gravestone({1200.f, 30-GROUND_HEIGHT/2.f-GRAVESTONE_HEIGHT/2.f});
    movingEntities->addEntity(grave);
    entityList.addEntity(grave);

    Entities::Objects::Obstacles::Thorns *thorns = new Entities::Objects::Obstacles::Thorns({1300.f, 30-GROUND_HEIGHT/2.f - THORNS_HEIGHT/2.f});
    movingEntities->addEntity(thorns);
    entityList.addEntity(thorns);
}

void SecondLevel::buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities){
    
    

    Entities::Characters::Enemies::Skeleton *skeleton = nullptr;
    Entities::Characters::Enemies::Goblin *goblin = nullptr;
    Entities::Objects::Obstacles::Gravestone *grave = nullptr;

        int i = 0, n = 1;; // n = 1, terceiro esqueleto minimo
    for(i = 1; i < 8; i++){
        if(n == 0){
            grave = new Entities::Objects::Obstacles::Gravestone({1600.f + (float) i * 300.f, -GROUND_HEIGHT/2.f});
            movingEntities->addEntity(grave);
            entityList.addEntity(grave);
        }else if (n == 1){
            skeleton = new Entities::Characters::Enemies::Skeleton({1600.f + 300.f*(float)i, -GROUND_HEIGHT/2.f}, player, player2);
            movingEntities->addEntity(skeleton);
            entityList.addEntity(skeleton);
        }else{
            goblin = new Entities::Characters::Enemies::Goblin({1600.f + 300.f*(float)i, -GROUND_HEIGHT/2.f}, player, player2);
            movingEntities->addEntity(goblin);
            entityList.addEntity(goblin);
        }

        n = rand()%3;
    }
    
}
void SecondLevel::buildCharacters(Lists::EntityList *movingEntities){
    Entities::Characters::Enemies::Goblin *goblin = new Entities::Characters::Enemies::Goblin({400.f, 30-GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    goblin = new Entities::Characters::Enemies::Goblin({600.f, 30-GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    Entities::Characters::Enemies::Skeleton *skeleton = new Entities::Characters::Enemies::Skeleton({1000.f, 30-GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);

    goblin = new Entities::Characters::Enemies::Goblin({1500.f, -GROUND_HEIGHT/2.f}, player, player2);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    skeleton = new Entities::Characters::Enemies::Skeleton({1650.f, -GROUND_HEIGHT/2.f}, player, player2);
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

    buildStaticEntities(staticEntities);
    buildFloor(staticEntities, movingEntities);
    buildObjects(movingEntities);

    Entities::Characters::Player *player = new Entities::Characters::Player({-100.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, true);
    movingEntities->addEntity(player);
    entityList.addEntity(player);

    hud.setPlayer1(player);

    Entities::Characters::Player *player2 = nullptr;
    if(!singlePlayer){
        player2 = new Entities::Characters::Player({-50.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, false);
        movingEntities->addEntity(player2);
        entityList.addEntity(player2);

        hud.setPlayer2(player2);
    }
    
    this->player = player;
    this->player2 = player2;

    buildCharacters(movingEntities);
    buildRandomEntities(staticEntities, movingEntities);
    buildStatues(staticEntities);//Tridimensionaliza as estátuas
        
    collisionManager.setMovingEntities(movingEntities);
    collisionManager.setStaticEntities(staticEntities);

    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl()); 

    if(player2){
        inputManager->subscribe("pressed", player2->getPlayerControl());
        inputManager->subscribe("released", player2->getPlayerControl());   
    }
}

void SecondLevel::load(){
    Lists::EntityList *movingEntities = Data::Level::loadSnapshots(id);
    Lists::EntityList *staticEntities = new Lists::EntityList();

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
        std::cout << i << "\n";
        if(entityList[i]) {
            i != 0 ? std::cout << entityList[i-1]->getType() << "\n" : std::cout << entityList[i]->getType() << "\n";
            delete entityList[i];
        }
    } 

    player = nullptr;
    player2 = nullptr;

    entityList.clearAll();

    if(collisionManager.getMovingEntities()){
        delete collisionManager.getMovingEntities();
    }

    if(collisionManager.getStaticEntities()){
        delete collisionManager.getStaticEntities();
    }

    buildFloor(staticEntities, movingEntities);
    
    buildStaticEntities(staticEntities);
    
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

    buildStatues(staticEntities);

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

void SecondLevel::createPlayer2(){
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