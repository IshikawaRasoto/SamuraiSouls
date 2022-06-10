#include "Managers/Control/MenuKeys.hpp"

using namespace Managers::Control;

MenuKeys::MenuKeys(
    std::string up,
    std::string down,
    std::string execute
){
    this->up = up;
    this->down = down;
    this->execute = execute;
}