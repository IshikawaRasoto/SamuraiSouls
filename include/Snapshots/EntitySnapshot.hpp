#pragma once

#include <SFML/System/Vector2.hpp>
#include <string>

#include "Type.hpp"

namespace Snapshots{

class EntitySnapshot{
protected:

    sf::Vector2f position;
    sf::Vector2f speed;
    bool facingLeft;
    Type entityType;

public:
    EntitySnapshot(   
        Type entityType = Type::Empty,
        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f),
        sf::Vector2f speed = sf::Vector2f(0.0f, 0.0f),
        bool facingLeft = false
    );
    ~EntitySnapshot();

    sf::Vector2f getPosition();
    bool getFacingLeft();
    Type getEntityType();
    sf::Vector2f getSpeed();

    virtual std::string toString();
};

}