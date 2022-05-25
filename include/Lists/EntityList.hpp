#pragma once

#include <list>
#include "Entities/Entity.hpp"

namespace Lists{

class EntityList{

private:
    std::list<Entities::Entity*> list;
public:
    EntityList();
    ~EntityList();

    void updateAll(float dt);
    void renderAll();

    bool addEntity(Entities::Entity* entity);
    bool removeEntity(Entities::Entity* entity);

    const int getSize();

    Entities::Entity* operator[](int id);
};

}