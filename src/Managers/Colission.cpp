#include "Colission.hpp"
#include <cmath>

using namespace Managers;

Colission::Colission(
    Lists::EntityList *movingEntities, 
    Lists::EntityList *staticEntities
){
    this->movingEntities = movingEntities;
    this->staticEntities = staticEntities;
}

Colission::Colission(){
    movingEntities = nullptr;
    staticEntities = nullptr;
}

Colission::~Colission(){}

void Colission::checkColission(){

    if(!movingEntities || !staticEntities){
        return;
    }

    Entities::Entity *entity1 = nullptr, *entity2 = nullptr;
    sf::Vector2f centerDistance, intersect; 

    for(int i = 0; i < movingEntities->getSize(); i++){
        entity1 = movingEntities[i];
        for(int j = 0; j < staticEntities->getSize(); j++){
            entity2 = movingEntities[j];

            centerDistance.x = entity1->getPosition().x - entity2->getPosition().x;
            centerDistance.y = entity1->getPosition().y - entity2->getPosition().y;

            intersect.x = fabs(centerDistance.x) - (entity1->getHitbox().x/2 + entity2->getHitbox().x/2);

        }
    }

}
