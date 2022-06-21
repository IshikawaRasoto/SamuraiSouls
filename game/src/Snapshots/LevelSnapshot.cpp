#include "Snapshots/LevelSnapshot.hpp"

using namespace Snapshots;

LevelSnapshot::LevelSnapshot(
    Patterns::StateId stateId,
    int points
){
    this->stateId = stateId;
    this->points = points;
}

LevelSnapshot::~LevelSnapshot() {}

int LevelSnapshot::getPoints(){
    return points;
}

Patterns::StateId LevelSnapshot::getStateId(){
    return stateId;
}

std::string LevelSnapshot::toString(){
    return std::to_string(points);
}