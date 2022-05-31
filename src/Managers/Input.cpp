#include "Managers/Input.hpp"

using namespace Managers;

InputManager::InputManager(){
    currentEvent = UNKNOWN;
    currentKey = UNKNOWN;
}
InputManager::~InputManager(){}

InputManager* InputManager::getInstance(){
    if(!instance){
        instance = new InputManager();
    }

    return instance;
}

std::string InputManager::getCurrentEvent(){
    return currentEvent;
}

std::string InputManager::getCurrentKey(){
    return currentKey;
}

void InputManager::subscribe(std::string type, Observer<InputManager> *observer){
    observers.insert(InputManagerPair(type, observer));
}

void InputManager::unsubscribe(std::string type, Observer<InputManager> *observer){
    //TODO
}

void InputManager::update(EventManager *subject){
    currentEvent = subject->getCurrentEvent();
    currentKey = subject->getCurrentKey();

    notify();
}

void InputManager::notify(){
    for(auto &it : observers){
        if(it.first == currentEvent){
            it.second->update(this);
        }
    }
}

