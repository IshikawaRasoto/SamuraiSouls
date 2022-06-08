#include "Managers/Keyboard.hpp"

using namespace Managers;

std::map<sf::Keyboard::Key, std::string> Keyboard::Key({
    {sf::Keyboard::W, "W"},
    {sf::Keyboard::A, "A"},
    {sf::Keyboard::S, "S"},
    {sf::Keyboard::D, "D"},
    {sf::Keyboard::Left, "Left"},
    {sf::Keyboard::Right, "Right"},
    {sf::Keyboard::Up, "Up"},
    {sf::Keyboard::Down, "Down"},
    {sf::Keyboard::Escape, "Esc"},
    {sf::Keyboard::Enter, "Enter"},
});