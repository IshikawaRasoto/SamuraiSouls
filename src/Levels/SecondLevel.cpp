#include "Levels/SecondLevel.hpp"
using namespace Levels;

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Ground.hpp"
#include "Entities/Objects/Surfaces/MiniGround.hpp"
#include "Entities/Objects/Obstacles/Thorns.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"
#include "Entities/Characters/Enemies/Boss.hpp"

SecondLevel::SecondLevel(Patters::StateMachine* stateMachine):
    Level(stateMachine, SECOND_LEVEL_BACKGROUND_DIR, Patterns::StateId::SecondLevel)
{
    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntities = new Lists::EntityList();

    int i , j;

    for(i = -3; i < 6; i++){
        Entities::Objects::Surfaces::Ground *ground = new Entities::Objects::Surfaces::Ground({float(i)*GROUND_WITH, 10});
        staticEntities->addEntity(ground);
        entityList.addEntity(ground);
    }

    for(j = 0; j < 3; j++){
        Entities::Objects::Obstacles::Thorns *thorns = new Entities::Objects::Obstacles::Thorns({float(i)*GROUND_WIDTH + float(j) * THORNS_WIDTH, 10});
        staticEntities->addEntity(thorns);
        entityList.addEntity(thorns);
    }

    for(i; i < 9; i++){
        Entities::Objects::Surfaces::Ground *ground = new Entities::Objects::Surfaces::Ground({float(i)*GROUND_WITH + float(j) * THORNS_WIDTH, 10});
        staticEntities->addEntity(ground);
        entityList.addEntity(ground);
    }

    for(i; i < 15; i++){
        Entities::Objects::Surfaces::Ground *ground = new Entities::Objects::Surfaces::Ground({float(i)*GROUND_WITH + float(j) * THORNS_WIDTH, 0});
        staticEntities->addEntity(ground);
        entityList.addEntity(ground);
    }

    srand(time(NULL));
    if(rand()%2){
        for(j; j<5; j++){
            Entities::Objects::Obstacles::Thorns *thorns = new Entities::Objects::Obstacles::Thorns({float(i)*GROUND_WIDTH + float(j) * THORNS_WIDTH, 0});
            staticEntities->addEntity(thorns);
            entityList.addEntity(thorns);
        }
    }else{
        for(j; j<5; j++){
            Entities::Objects::Surfaces::MiniGround *miniGround = new Entities::Objects::Surfaces::Miniground({float(i)*GROUND_WIDTH + float(j) * THORNS_WIDTH, 0});
            staticEntities->addEntity(miniGround);
            entityList.addEntity(miniGround);
        }
    }

    for(i; i < 22; i++){
        Entities::Objects::Surfaces::Ground *ground = new Entities::Objects::Surfaces::Ground({float(i)*GROUND_WITH + float(j) * THORNS_WIDTH, 0});
        staticEntities->addEntity(ground);
        entityList.addEntity(ground);
    }
    for(i; i < 30; i++){
        Entities::Objects::Surfaces::Ground *ground = new Entities::Objects::Surfaces::Ground({float(i)*GROUND_WITH + float(j) * THORNS_WIDTH, 0});
        staticEntities->addEntity(ground);
        entityList.addEntity(ground);
    }


}

SecondLevel::~SecondLevel(){}

void SecondLevel::centerView(){
    sf::Vector2f viewPosition;
    viewPosition.x = player->getPosition().x + WINDOW_SIZE_X/4;
    viewPosition.y = -WINDOW_SIZE_Y/2 + PAVEMENT_HEIGHT/2;

    graphicsManager->centerView(viewPosition);
    // points.setPosition(viewPosition);
    // life.setPosition({viewPosition.x, viewPosition.y + 30});
    background.setPosition(viewPosition);
}

void SecondLevel::reset(){
    //TODO
}

void SecondLevel::update(float dt){
    entityList.updateAll(dt);

    if(player->getHP() <= 0){
        getStateMachine()->changeCurrentState(Patterns::StateId::GameOver);
    }

    collisionManager.checkCollision();

    // points.setValue("Points: " + player->getPts());
    // life.setValue("HP: " + player->getHP());
}   