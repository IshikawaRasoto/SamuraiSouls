#pragma once

#include <string>

namespace Control{

struct PlayerKeys{
    std::string jump;
    std::string left;
    std::string right;
    std::string attack;

    PlayerKeys();
    PlayerKeys(const std::string jump, const std::string left, const std::string right, const std::string attack);
};

}

