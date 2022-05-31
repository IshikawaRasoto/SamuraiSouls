#include "Managers/EventType.hpp"

using namespace Managers;

std::map<sf::Event::EventType, std::string> Event::Types({
    {sf::Event::KeyPressed, "pressed"},
    {sf::Event::KeyReleased, "released"},
    {sf::Event::Closed, "closed"}
})