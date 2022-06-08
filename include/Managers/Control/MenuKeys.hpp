#pragma once

#include <string>

namespace Managers{
namespace Control{

struct MenuKeys{
    std::string up;
    std::string down;
    std::string execute;

    MenuKeys(
        std::string up = "",
        std::string down = "",
        std::string execute = ""
    );
};
}
}