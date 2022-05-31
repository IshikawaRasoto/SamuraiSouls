#include <map> 
#include <string>
#include <SFML/Window/Event.hpp>

namespace Managers{
struct Keyboard{
    static std::map<sf::Keyboard::Key, std::string> Key;
};
}