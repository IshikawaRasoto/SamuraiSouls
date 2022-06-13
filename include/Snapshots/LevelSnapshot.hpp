#pragma once

#include "Patterns/State.hpp"
#include <string>

namespace Snapshots{

class LevelSnapshot{
private:
    Patterns::StateId stateId;
    int points;
public:
    LevelSnapshot(
        Patterns::StateId stateId = Patterns::StateId::Unknown,
        int points = 0
    );

    ~LevelSnapshot();

    Patterns::StateId getStateId();
    int getPoints();

    std::string toString();
};

}