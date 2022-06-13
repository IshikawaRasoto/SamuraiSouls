#include "Snapshots/PlayerSnapshot.hpp"

using namespace Snapshots;

PlayerSnapshot::PlayerSnapshot(
    bool isPlayerOne,
    int hp,
    sf::Vector2f position,
    sf::Vector2f speed,
    bool facingLeft
):
    EntitySnapshot(Type::Player, position, speed, facingLeft)
{
    this->hp = hp;
    this->isPlayerOne = isPlayerOne;
}

PlayerSnapshot::~PlayerSnapshot(){}

int PlayerSnapshot::getHp(){
    return hp;
}

bool PlayerSnapshot::getIsPlayerOne(){
    return isPlayerOne;
}

std::string PlayerSnapshot::toString(){
    std::string type = std::to_string(entityType);
    std::string positionString = std::to_string(position.x) + "," + std::to_string(position.y);
    std::string speedString = std::to_string(speed.x) + "," + std::to_string(speed.y);
    std::string playerOne = std::to_string(isPlayerOne);
    std::string hpString = std::to_string(hp);
    std::string facingLeftString = std::to_string(facingLeft);
    
    return type + "," + positionString + "," + speedString + "," + facingLeftString + "," + hpString + "," + playerOne;
}