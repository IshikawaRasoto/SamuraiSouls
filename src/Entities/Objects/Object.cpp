#include "Entities/Objects/Object.hpp"
using namespace Entities::Objects;

Object::Object(Type t, sf::Vector2f position, sf::Vector2f hitbox):
    Entity(t, position, hitbox)
{}

Object::~Object(){}