#include "Levels/FirstLevel.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Obstacles/Barrel.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"

using namespace Levels;

template<class T>
void FirstLevel::createStairs(int size, float x, sf::Vector2u objectSize, Lists::EntityList *staticEntities){
    for(float i = 0; i < size; i++){
        for(float j = i; j < size; j++){
            T *object = new T({x+j*objectSize.x, -PAVEMENT_HEIGHT/2 - (objectSize.y*i + objectSize.y/2)});
            staticEntities->addEntity(object);
            entityList.addEntity(object);
        }
    }
}

template<class T>
void FirstLevel::createWall(int size, float x, sf::Vector2u objectSize, Lists::EntityList *staticEntities){
    for(float i = 0; i < size; i++){
        T *object = new T({x, -PAVEMENT_HEIGHT/2 - (objectSize.y*i + objectSize.y/2)});
        staticEntities->addEntity(object);
        entityList.addEntity(object);
    }
}

FirstLevel::FirstLevel(Patterns::StateMachine* stateMachine):
    Level(stateMachine, FIRST_LEVEL_BACKGROUND_DIR, Patterns::StateId::FirstLevel)
    // points("Points: 0")
{
    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntities = new Lists::EntityList();

    //Altura é invertida no SFML.

    /*
        Como a origin de todos os sprites é igual a metade do tamanho dos mesmos, 
        é necessário sempre trabalhar com a metade do tamanho dos sprites na hora de posicioná-los
    */

    for(int i = -2; i < 30; i++){
        Entities::Objects::Surfaces::Pavement *pavement = new Entities::Objects::Surfaces::Pavement({float(i)*PAVEMENT_WIDTH, 0});
        staticEntities->addEntity(pavement);
        entityList.addEntity(pavement);
    }

    createWall<Entities::Objects::Surfaces::InvisibleBlock>(10,-150.0f, {BLOCK_WIDTH, BLOCK_HEIGHT}, staticEntities);

    Entities::Objects::Obstacles::Barrel *barrel = new Entities::Objects::Obstacles::Barrel({50.f, -PAVEMENT_HEIGHT/2.f - BARREL_HEIGHT/2.f});
    staticEntities->addEntity(barrel);
    entityList.addEntity(barrel);

    srand(time(NULL));

    createStairs<Entities::Objects::Obstacles::Box>(2, 150.0f, {BOX_WIDTH, BOX_HEIGHT}, staticEntities);
    

    Entities::Characters::Player *player = new Entities::Characters::Player({0.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, false);
    movingEntities->addEntity(player);
    entityList.addEntity(player);
    
    Entities::Characters::Enemies::Goblin *goblin = new Entities::Characters::Enemies::Goblin({250.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    Entities::Characters::Enemies::Skeleton *skeleton = new Entities::Characters::Enemies::Skeleton({700.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);


    if(rand()%2){
        createStairs<Entities::Objects::Obstacles::Box>(rand()%5, 1000.0f, {BOX_WIDTH, BOX_HEIGHT},staticEntities );
    }else{
        createStairs<Entities::Objects::Obstacles::Barrel>(rand()%5, 1000.0f, {BARREL_WIDTH, BARREL_HEIGHT},staticEntities);
    }

    goblin = new Entities::Characters::Enemies::Goblin({1400.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    goblin = new Entities::Characters::Enemies::Goblin({1500.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);
    movingEntities->addEntity(goblin);
    entityList.addEntity(goblin);

    createWall<Entities::Objects::Obstacles::Barrel>(2,1575.0f, {BARREL_WIDTH, BARREL_HEIGHT}, staticEntities);

    skeleton = new Entities::Characters::Enemies::Skeleton({1650.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);    

    if(rand()%2){
        goblin = new Entities::Characters::Enemies::Goblin({2000.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2},player);
        movingEntities->addEntity(goblin);
        entityList.addEntity(goblin);
    }else{
        barrel = new Entities::Objects::Obstacles::Barrel({2000.f, -PAVEMENT_HEIGHT/2.f - BARREL_HEIGHT/2.f});
        staticEntities->addEntity(barrel);
        entityList.addEntity(barrel);
    }

    skeleton = new Entities::Characters::Enemies::Skeleton({2200.0f, -PAVEMENT_HEIGHT/2-SKELETON_HEIGHT/2},player);
    movingEntities->addEntity(skeleton);
    entityList.addEntity(skeleton);  

        

    this->player = player;
        
    collisionManager = Managers::CollisionManager(movingEntities, staticEntities);

    
    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl());      
    
}

FirstLevel::~FirstLevel(){}

void FirstLevel::centerView(){
    sf::Vector2f viewPosition;
    viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    viewPosition.y = -WINDOW_SIZE_Y/2 + PAVEMENT_HEIGHT/2;

    graphicsManager->centerView(viewPosition);
    // points.setPosition(viewPosition);
    // life.setPosition({viewPosition.x, viewPosition.y + 30});
    background.setPosition(viewPosition);
}

void FirstLevel::reset(){
    //TODO
}

void FirstLevel::update(float dt){
    entityList.updateAll(dt);

    if(player->getHP() <= 0){
        getStateMachine()->changeCurrentState(Patterns::StateId::GameOver);
    }

    collisionManager.checkCollision();

    // points.setValue("Points: " + player->getPts());
    // life.setValue("HP: " + player->getHP());

    render();
}