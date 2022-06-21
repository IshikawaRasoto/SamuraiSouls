#pragma once

#include <list>
#include "Entities/Entity.hpp"
#include "Lists/EntityList.hpp"

namespace Managers{

class CollisionManager{
private:

    Lists::EntityList *movingEntities;
    Lists::EntityList *staticEntities;

public:

    CollisionManager(
        Lists::EntityList *movingEntities = nullptr, 
        Lists::EntityList *staticEntities = nullptr
    );

    ~CollisionManager();

    Lists::EntityList* getMovingEntities();
    Lists::EntityList* getStaticEntities();

    void setMovingEntities(Lists::EntityList *entities);
    void setStaticEntities(Lists::EntityList *entities);
    
    void checkCollision();
};

}