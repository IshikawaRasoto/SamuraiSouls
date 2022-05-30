#include "Managers/Collision.hpp"
#include <cmath>

using namespace Managers;

CollisionManager::CollisionManager(
    Lists::EntityList *movingEntities, 
    Lists::EntityList *staticEntities
){
    this->movingEntities = movingEntities;
    this->staticEntities = staticEntities;
}

CollisionManager::CollisionManager(){
    movingEntities = nullptr;
    staticEntities = nullptr;
}

CollisionManager::~CollisionManager(){}

void CollisionManager::checkCollision(){

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

            intersect.x = fabs(centerDistance.x) - (entity1->getSize().x/2 + entity2->getSize().x/2);
            intersect.y = fabs(centerDistance.y) - (entity1->getSize().y/2 + entity2->getSize().y/2);

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

            intersect.x = fabs(centerDistance.x) - (entity1->getSize().x/2 + entity2->getSize().x/2);
            intersect.y = fabs(centerDistance.y) - (entity1->getSize().y/2 + entity2->getSize().y/2);

            if(intersect.x < 0.0f && intersect.y < 0.0f){
                entity1->collide(entity2, intersect);
                entity2->collide(entity1, intersect);
            }
        }
    }

}