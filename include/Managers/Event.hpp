#pragma once

#include <SFML/Graphics.hpp>
#include "EventListener.hpp"
#include "EventType.hpp"
#include <map>

namespace Managers{

class EventManager{
private:
    std::multimap<EventType, EventListener*> listeners;

public:

    void subscribe(EventType type, EventListener *listener);
    void unsubscribe(EventType type, EventListener *listener);
    void notify(EventType type);
    
};

}
