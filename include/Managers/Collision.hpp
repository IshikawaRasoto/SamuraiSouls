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
        Lists::EntityList *movingEntities, 
        Lists::EntityList *staticEntities
    );

    CollisionManager();
    ~CollisionManager();
    
    void checkColision();
};

}