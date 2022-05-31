#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <string>

#include "config.hpp"

#include "EventType.hpp"
#include "Graphics.hpp"

#include "Patterns/Subject.hpp"
#include "Patterns/Observer.hpp"

using namespace Patterns;

namespace Managers{

class EventManager : public Subject<EventManager>{
private:
    sf::Window* window;

    std::string currentEvent;
    std::string currentKey;

    static EventManager* instance;
public:
    EventManager(sf::Window* window = GraphicsManager::getInstance()->getWindow());
    ~EventManager();

    std::string getCurrentEvent();
    std::string getCurrentKey();

    void subscribe(std::string type, Observer<EventManager>* listener);
    void unsubscribe(std ::string type, Observer<EventManager>*listener);
    void notify();
    void pollEvents();

    static EventManager* getInstance();
};

using EventObserverPair = std::pair<std::string, Observer<EventManager>*>;
}

