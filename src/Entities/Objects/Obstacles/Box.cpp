#pragma once

#include "Entities/Objects/Obstacles/Box.hpp"
using namespace Entities::Objects;

Obstacles::Box::Box(sf::Vector2f position):
    Object(Type::Box, position, sf::Vector2f(BOX_WIDTH, BOX_HEIGHT))
    {}

