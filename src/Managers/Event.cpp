#include "Managers/Event.hpp"
#include "Managers/Keyboard.hpp"

using namespace Managers;

EventManager::EventManager(sf::Window* window):
    Patterns::Subject()
{
    this->window = window;
}

EventManager::~EventManager(){}

EventManager* EventManager::getInstance(){
    if(!instance){
        instance = new EventManager();
    }

    return instance;
}

void EventManager::subscribe(std::string type, Observer* listener){
    observers.insert(EventListenerPair(type, listener));
}

void EventManager::unsubscribe(std::string type, Observer* listener){
    //TODO
}

void EventManager::notify(std::string type){
    for(auto &it : listeners){
        if(it.first == type){
            it.second->update(type);
        }
    }
}

void EventManager::notify(std::string type, std::string key){
    for(auto &it : listeners){
        if(it.first == type){
            it.second->update(type, key);
        }
    }
}

void EventManager::pollEvents(){
    if(!window) return;
    sf::Event event;
    std::string eventType, key;

    while(window->pollEvent(event)){
        eventType = Event::Types.find(event.type) != Event::Types.end() 
                    ? Event::Types[event.type] : "Unknown";


        if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased){
            key = Keyboard::Key.find(event.key.code) != Keyboard::Key.end() 
                  ? Keyboard::Key[event.key.code] : "Unknown";

            notify(eventType, key);
        }else{
            notify(eventType);
        }
    }
}