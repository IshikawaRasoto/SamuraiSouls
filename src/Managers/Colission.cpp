#include "Managers/Colission.hpp"
#include <cmath>

using namespace Managers;

ColissionManager::ColissionManager(
    Lists::EntityList *movingEntities, 
    Lists::EntityList *staticEntities
){
    this->movingEntities = movingEntities;
    this->staticEntities = staticEntities;
}

ColissionManager::ColissionManager(){
    movingEntities = nullptr;
    staticEntities = nullptr;
}

ColissionManager::~ColissionManager(){}

void ColissionManager::checkColission(){

    if(!movingEntities || !staticEntities){
        return;
    }

    Entities::Entity *entity1 = nullptr, *entity2 = nullptr;
    sf::Vector2f centerDistance, intersect; 

    for(int i = 0; i < movingEntities->getSize(); i++){
        entity1 = (*movingEntities)[i];
        for(int j = 0; j < staticEntities->getSize(); j++){
            entity2 = (*staticEntities)[j];

            centerDistance.x = entity1->getPosition().x - entity2->getPosition().x;
            centerDistance.y = entity1->getPosition().y - entity2->getPosition().y;

            intersect.x = fabs(centerDistance.x) - (entity1->getHitbox().x/2 + entity2->getHitbox().x/2);
            intersect.y = fabs(centerDistance.y) - (entity1->getHitbox().y/2 + entity2->getHitbox().y/2);

            if(intersect.x < 0.0f && intersect.y < 0.0f){
                entity1->collide(entity2, intersect);
            }
        }
    }

    for(int i = 0; i < movingEntities->getSize(); i++){
        entity1 = (*movingEntities)[i];
        for(int j = 0; j < movingEntities->getSize(); j++){
            entity2 = (*movingEntities)[j];

            centerDistance.x = entity1->getPosition().x - entity2->getPosition().x;
            centerDistance.y = entity1->getPosition().y - entity2->getPosition().y;

            intersect.x = fabs(centerDistance.x) - (entity1->getHitbox().x/2 + entity2->getHitbox().x/2);
            intersect.y = fabs(centerDistance.y) - (entity1->getHitbox().y/2 + entity2->getHitbox().y/2);

            if(intersect.x < 0.0f && intersect.y < 0.0f){
                entity1->collide(entity2, intersect);
                entity2->collide(entity1, intersect);
            }
        }
    }

}
