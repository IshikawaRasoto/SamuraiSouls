#pragma once

#include <vector>

#include "Snapshots/EntitySnapshot.hpp"
#include "Snapshots/LevelSnapshot.hpp"
#include "Snapshots/PlayerSnapshot.hpp"
#include "Lists/EntityList.hpp"

#include "Entities/Characters/Player.hpp"
#include "Entities/Characters/Enemies/Goblin.hpp"
#include "Entities/Characters/Enemies/Skeleton.hpp"
#include "Entities/Characters/Enemies/Boss.hpp"
#include "Entities/Characters/Enemies/Enemy.hpp"
#include "Entities/FireBall.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Objects/Obstacles/Barrel.hpp"
#include "Entities/Objects/Obstacles/Box.hpp"
#include "Entities/Objects/Obstacles/Gravestone.hpp"
#include "Entities/Objects/Obstacles/Thorns.hpp"
#include "Entities/Objects/Obstacles/Wagon.hpp"

#define LEVELDATA_SNAPSHOT_BASE_FILENAME "./snapshot"
#define LEVELDATA_SNAPSHOT_FILE_EXTENSION ".txt"

using namespace Entities::Characters;
using namespace Entities::Objects::Obstacles;

namespace Data{

class Level{
public:

    static Characters::Player* buildPlayer(Snapshots::PlayerSnapshot* playerSnapshot);
    static Characters::Enemies::Boss* buildBoss(Snapshots::EntitySnapshot* entitySnapshot, Entities::FireBall *fireball);

    template<class T>
    static T* buildEntity(Snapshots::EntitySnapshot* entitySnapshot);

    template<class T>
    static T* buildEnemy(Snapshots::EntitySnapshot* entitySnapshot);

    static void saveSnapshots(std::vector<Snapshots::EntitySnapshot*> snapshots, Snapshots::LevelSnapshot* levelSnapshot);
    static Lists::EntityList* loadSnapshots(Patterns::StateId levelState);
};

template<class T>
T* Level::buildEntity(Snapshots::EntitySnapshot* entitySnapshot){
    T* entity = new T(entitySnapshot->getPosition());

    (static_cast<Entities::Entity*>(entity))->setSpeed(entitySnapshot->getSpeed());
    (static_cast<Entities::Entity*>(entity))->setFacingLeft(entitySnapshot->getFacingLeft());

    return entity;
}

template<class T>
T* Level::buildEnemy(Snapshots::EntitySnapshot* entitySnapshot){
    T* enemy = new T(entitySnapshot->getPosition());

    (static_cast<Characters::Enemies::Enemy*>(enemy))->setSpeed(entitySnapshot->getSpeed());
    (static_cast<Characters::Enemies::Enemy*>(enemy))->setFacingLeft(entitySnapshot->getFacingLeft());

    return enemy;
}

}