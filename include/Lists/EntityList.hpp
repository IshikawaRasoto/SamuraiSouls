#pragma once

#include <vector>

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
    bool addEntity(std::vector<Entities::Entity*> entities);
    bool removeEntity(Entities::Entity* entity);

    const int getSize();

    Entities::Entity* operator[](unsigned int size);
};

}