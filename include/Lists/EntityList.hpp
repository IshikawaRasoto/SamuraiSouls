#pragma once

#include "List.hpp"
#include "Entities/Entity.hpp"

namespace Lists{

class EntityList{

private:
    List<Entities::Entity> list;
public:
    EntityList();
    ~EntityList();

    void updateAll(float dt);
    void renderAll();

    bool addEntity(Entities::Entity* entity);
    bool removeEntity(Entities::Entity* entity);

    const int getSize();

    Entities::Entity* operator[](unsigned int size);
};

}