#pragma once

#include <SFML/Window/Event.hpp>
#include <map>
#include <string>
#include "EventObserver.hpp"
#include "InputObserver.hpp"

namespace Managers{

class InputManager: public EventObserver{
private:
    InputManager();
    std::multimap<std::string, InputObserver*> listeners;
    InputManager* instance;
public:
    static InputManager* getInstance();
    void update(std::string type, std::string key);
    void notify(std::string type, std::string key); 

    ~InputManager();

};
}