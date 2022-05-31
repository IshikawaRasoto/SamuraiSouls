#pragma once

#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include "Graphics.hpp"
#include "EventObserver.hpp"
#include "EventType.hpp"
#include "Patterns/Subject.hpp"
#include <map>
#include <string>

namespace Managers{

using EventListeners = std::multimap<std::string, EventObserver*>;
using EventListenerPair = std::pair<std::string, EventObserver*>;

class EventManager : public Patterns::Subject{
private:
    sf::Window* window;
    EventListeners observers;

    static EventManager* instance;
public:
    EventManager(sf::Window* window = GraphicsManager::getInstance()->getWindow());
    ~EventManager();

    void subscribe(std::string type, Observer* listener);
    void unsubscribe(std ::string type, Observer* listener);
    void notify(std::string type);
    void notify(std::string type, std::string key);
    void pollEvents();
    
    static EventManager* getInstance();
};

}
