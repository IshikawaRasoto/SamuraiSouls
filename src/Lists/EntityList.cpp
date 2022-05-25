#include "Lists/EntityList.hpp"

using namespace Lists;

EntityList::EntityList(){
    list.clear();
}

EntityList::~EntityList(){
    std::list<Entities::Entity*>::iterator it = list.begin();

    while(it != list.end()){
        delete *it;
        it++;
    }
}

bool EntityList::addEntity(Entities::Entity *entity){

    if(!entity){
        return false;
    }

    list.push_back(entity);

    return true;
}

bool EntityList::removeEntity(Entities::Entity *entity){
    return false;
}

void EntityList::updateAll(float dt){
    for(auto it : list){
        it->update(dt);
    }
}

void EntityList::renderAll(){
    for(auto it : list){
        it->render();
    }
}

Entities::Entity* EntityList::operator[](int id){
    if(id < 0 || id >= list.size()){
        return nullptr;
    }

    int i = 0;

    for(auto it : list){
        if(i == id){
            return it;
        }
    }

    return nullptr;
}

const int EntityList::getSize(){
    return list.size();
}