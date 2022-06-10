/*#include "Levels/SecondLevel.hpp"
using namespace Levels;

#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Surfaces/InvisibleBlock.hpp"
#include "Entities/Objects/Surfaces/Ground.hpp"
#include "Entities/Objects/Surfaces/MiniGround.hpp"
#include "Entities/Objects/Obstacles/Thorns.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"

SecondLevel::SecondLevel(Patters::StateMachine* stateMachine):
    Level(stateMachine, SECOND_LEVEL_BACKGROUND_DIR, Patterns::StateId::SecondLevel)
{
    Lists::EntityList *movingEntities = new Lists::EntityList();
    Lists::EntityList *staticEntities = new Lists::EntityList();
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
}   */