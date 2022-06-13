#include "Snapshots/EntitySnapshot.hpp"

using namespace Snapshots;

EntitySnapshot::EntitySnapshot(
    Type entityType,
    sf::Vector2f position,
    sf::Vector2f speed,
    bool facingLeft
)
{
    this->entityType = entityType;
    this->position = position;
    this->speed = speed;
    this->facingLeft = facingLeft;
}

EntitySnapshot::~EntitySnapshot(){}

Type EntitySnapshot::getEntityType(){
    return entityType;
}

sf::Vector2f EntitySnapshot::getPosition(){
    return position;
}

sf::Vector2f EntitySnapshot::getSpeed(){
    return speed;
}

bool EntitySnapshot::getFacingLeft(){
    return facingLeft;
}

std::string EntitySnapshot::toString(){
    std::string type = std::to_string(entityType);
    std::string positionString = std::to_string(position.x) + "," + std::to_string(position.y);
    std::string speedString = std::to_string(speed.x) + "," + std::to_string(speed.y);
    std::string facingLeftString = std::to_string(facingLeft);

    return type + "," + positionString + "," + speedString + "," + facingLeftString;
}