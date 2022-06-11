#include "Levels/FirstLevel.hpp"

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Obstacles/Barrel.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Pavement.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"

#include "Levels/StructuresFactory.hpp"

using namespace Levels;
using namespace Entities::Objects;
using namespace Entities::Characters;

FirstLevel::FirstLevel(Patterns::StateMachine* stateMachine, const bool singlePlayer):
    Level(stateMachine, FIRST_LEVEL_BACKGROUND_DIR, Patterns::StateId::FirstLevel, singlePlayer)
    // points("Points: 0")
{
    srand(time(NULL));

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

    Entities::Characters::Player *player2 = nullptr;
    if(!singlePlayer){
        player2 = new Entities::Characters::Player({50.0f, -PAVEMENT_HEIGHT/2-PLAYER_HEIGHT/2}, false);
        movingEntities->addEntity(player2);
        entityList.addEntity(player2);
    }
    
    this->player = player;
    this->player2 = player2;

    buildObjects(staticEntities);
    buildCharacters(movingEntities);
    buildRandomEntities(staticEntities, movingEntities);
        
    collisionManager = Managers::CollisionManager(movingEntities, staticEntities);
    
    inputManager->subscribe("pressed", player->getPlayerControl());
    inputManager->subscribe("released", player->getPlayerControl()); 

    inputManager->subscribe("pressed", player2->getPlayerControl());
    inputManager->subscribe("released", player2->getPlayerControl());   

    inputManager->subscribe("pressed", &control);
}

FirstLevel::~FirstLevel(){}

void FirstLevel::centerView(){
    sf::Vector2f viewPosition;
    if(singlePlayer)
        viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    else
        viewPosition.x = (player->getPosition().x + player2->getPosition().x)/2;
    
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
        changeCurrentState(Patterns::StateId::GameOver);
    }

    collisionManager.checkCollision();

    // points.setValue("Points: " + player->getPts());
    // life.setValue("HP: " + player->getHP());

    render();
}

void FirstLevel::buildObjects(Lists::EntityList *staticEntities){
    std::vector<Entities::Entity*> structure;

    structure = 
        StructuresFactory<Surfaces::Pavement>::createFloor(-2, 30, {PAVEMENT_WIDTH, PAVEMENT_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    //Parede de blocos invisíveis para impedir a passagem do player para os extremos do nível. 
    structure = 
        StructuresFactory<Surfaces::InvisibleBlock>::createWall(10,-150.0f, {BLOCK_WIDTH, BLOCK_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    //Escada de caixas
    structure = 
        StructuresFactory<Obstacles::Box>::createStairs(2, 150.0f, {BOX_WIDTH, BOX_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    structure = 
        StructuresFactory<Obstacles::Barrel>::createWall(2,1575.0f, {BARREL_WIDTH, BARREL_HEIGHT});

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    Entities::Objects::Obstacles::Barrel *barrel = new Obstacles::Barrel({50.f, -PAVEMENT_HEIGHT/2.f - BARREL_HEIGHT/2.f});
    staticEntities->addEntity(barrel);
    entityList.addEntity(barrel);

}

void FirstLevel::buildRandomEntities(Lists::EntityList *staticEntities, Lists::EntityList *movingEntities){
    std::vector<Entities::Entity*> structure;
    Entities::Entity *entity;

    /*
        Aqui temos 50% de chance de ser criado uma escada de caixas e 50% de chance de ser criado uma caixa
        de barris. Além disso, cada escada também tem seu tamanho definido aleatoriamente.
    */

    int stairsSize = rand()%10;

    if(rand()%2){
        structure = 
            StructuresFactory<Obstacles::Box>::createStairs(stairsSize, 1000.0f, {BOX_WIDTH, BOX_HEIGHT});
    }else{
        structure = 
            StructuresFactory<Obstacles::Barrel>::createStairs(stairsSize, 1000.0f, {BARREL_WIDTH, BARREL_HEIGHT});
    }

    staticEntities->addEntity(structure);
    entityList.addEntity(structure);

    /*
        Aqui temos 50% de chance de ser criado um goblin e 50% de chance de ser criado uma caixa.
    */

    if(rand()%2){
        entity = new Enemies::Goblin({2000.0f, -PAVEMENT_HEIGHT/2-GOBLIN_HEIGHT/2}, player, player2);
        movingEntities->addEntity(entity);
    }else{
        entity = new Obstacles::Barrel({2000.f, -PAVEMENT_HEIGHT/2.f - BARREL_HEIGHT/2.f});
        staticEntities->addEntity(entity);
    }

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