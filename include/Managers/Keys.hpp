#include <map> 
#include <string>
#include <SFML/Window/Event.hpp>

namespace Managers{
struct Keys{
    static std::map<sf::Keyboard, std::string> keyboard;
};
}