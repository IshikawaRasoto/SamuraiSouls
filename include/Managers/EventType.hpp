#pragma once

#include <SFML/Window/Event.hpp>

enum class EventType{
    KeyDown = sf::Event::KeyPressed,
    KeyUp = sf::Event::KeyReleased
};
