#pragma once

#include <SFML/Window/Event.hpp>

#include <map>
#include <string>

#include "config.hpp"

#include "Patterns/Observer.hpp"
#include "Patterns/Subject.hpp"
#include "Event.hpp"

using namespace Patterns;

namespace Managers{

class InputManager: public Observer<EventManager>, 
                    public Subject<InputManager>
{
private:
    InputManager();
    static InputManager* instance;

    std::string currentKey;
    std::string currentEvent;
public:
    static InputManager* getInstance();
    std::string getCurrentEvent();
    std::string getCurrentKey();

    void subscribe(std::string type, Observer<InputManager> *observer);
    void unsubscribe(std::string type, Observer<InputManager> *observer);

    void update(EventManager *subject);
    void notify(); 

    ~InputManager();
};

using InputManagerPair = std::pair<std::string, Observer<InputManager>*>;

}