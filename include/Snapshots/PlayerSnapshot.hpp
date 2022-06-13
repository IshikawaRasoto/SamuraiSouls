#pragma once

#include "EntitySnapshot.hpp"

namespace Snapshots{

class PlayerSnapshot : public EntitySnapshot{
private:

    int hp;
    bool isPlayerOne;

public:

    PlayerSnapshot(
        bool isPlayerOne = false,
        int hp = 0,
        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f),
        sf::Vector2f speed = sf::Vector2f(0.0f, 0.0f),
        bool facingLeft = false
    );

    ~PlayerSnapshot();

    int getHp();
    bool getIsPlayerOne();

    std::string toString();
};

}