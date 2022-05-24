#include <list>
#include "Entities/Entity.hpp"
#include "Lists/EntityList.hpp"

namespace Managers{

class ColissionManager{
private:

    Lists::EntityList *movingEntities;
    Lists::EntityList *staticEntities;

public:

    ColissionManager(
        Lists::EntityList *movingEntities, 
        Lists::EntityList *staticEntities
    );

    ColissionManager();
    ~ColissionManager();

    void checkColission();
};

}