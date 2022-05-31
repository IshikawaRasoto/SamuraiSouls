#include "Managers/Event.hpp"
#include "Managers/Keyboard.hpp"

using namespace Managers;

EventManager* EventManager::instance = nullptr;

EventManager::EventManager(sf::Window* window)
{
    currentEvent = UNKNOWN;
    currentKey = UNKNOWN;
    this->window = window;
}

EventManager::~EventManager(){}

EventManager* EventManager::getInstance(){
    if(!instance){
        instance = new EventManager();
    }

    return instance;
}

void EventManager::subscribe(std::string type, Observer<EventManager>* listener){
    observers.insert(EventObserverPair(type, listener));
}

void EventManager::unsubscribe(std::string type, Observer<EventManager>* listener){
    //TODO
}

void EventManager::notify(){
    if(currentEvent == UNKNOWN) return;

    for(auto &it : observers){
        if(it.first == currentEvent){
            it.second->update(this);
        }
    }
}

void EventManager::pollEvents(){
    if(!window) return;
    sf::Event event;
    std::string eventType, key;

    while(window->pollEvent(event)){
        currentEvent = Event::Types.find(event.type) != Event::Types.end() 
                    ? Event::Types[event.type] : UNKNOWN;

        if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased){
            currentKey = Keyboard::Key.find(event.key.code) != Keyboard::Key.end() 
                  ? Keyboard::Key[event.key.code] : UNKNOWN;
        }

        notify();
    }
}

std::string EventManager::getCurrentEvent(){
    return currentEvent;
}

std::string EventManager::getCurrentKey(){
    return currentKey;
}

void GraphicsManager::update(EventManager* subject){
    std::string event = subject->getCurrentEvent();

    if(event == "closed"){
        done = true;
    }
}