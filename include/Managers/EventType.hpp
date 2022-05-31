#pragma once

#include <SFML/Window/Event.hpp>
#include <map>
#include <string>

namespace Managers{

class Event{
public:
    static std::map<sf::Event::EventType, std::string> Types;
};

}


