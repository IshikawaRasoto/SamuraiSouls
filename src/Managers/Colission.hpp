#include <list>
#include "../Entities/Entity.hpp"
#include "../Lists/EntityList.hpp"

namespace Managers{

class Colission{
private:

    Lists::EntityList *movingEntities;
    Lists::EntityList *staticEntities;

public:

    Colission(
        Lists::EntityList *movingEntities, 
        Lists::EntityList *staticEntities
    );

    Colission();
    ~Colission();

    void checkColission();
};

}