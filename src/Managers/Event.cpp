#include "Managers/Event.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

EventManager::EventManager()
    :hasFocus(true)
{
    loadBindings();
}

EventManager::~EventManager(){
    for(auto &itr : bindings){
        delete itr.second;
        itr.second = nullptr;
    }
}

bool EventManager::addBinding(Binding *binding){
    if(bindings.find(binding->name) != bindings.end()) 
        return false;

    return bindings.emplace(binding->name, binding).second;
}

bool EventManager::removeBinding(std::string name){
    auto itr = bindings.find(name);

    /*
        Se itr for igual a bindings.end(), significa que o mesmo não está presente no unorderned_map.
    */

    if(itr == bindings.end()) 
        return false;

    delete itr->second;
    bindings.erase(itr);
    
    return true;
}

void EventManager::setFocus(bool focus){
    hasFocus = focus;
}

void EventManager::handleEvent(sf::Event &event){

    for(auto &itr : bindings){
        Binding* bind = itr.second;

        for(auto &eventItr : bind->events){
            EventType sfmlEvent = (EventType) event.type;
            if(eventItr.first != sfmlEvent)
                continue;

            if(sfmlEvent == EventType::KeyDown || sfmlEvent == EventType::KeyUp){
                if (eventItr.second.code == event.key.code){
                    if(bind->details.keyCode == -1){
                        bind->details.keyCode = eventItr.second.code;
                    }

                    bind->eventCount++;
                    break;
                }
            }else if(sfmlEvent == EventType::MouseButtonDown || sfmlEvent == EventType::MouseButtonUp){
                if(eventItr.second.code == event.mouseButton.button){
                    bind->details.mouse.x = event.mouseButton.x;
                    bind->details.mouse.y = event.mouseButton.y;

                    if(bind->details.keyCode == -1){
                        bind->details.keyCode = eventItr.second.code;
                    }

                    bind->eventCount++;
                    break;
                }
            }else {
                if(sfmlEvent == EventType::MouseWheel){
                    bind->details.mouseWheelDelta = event.mouseWheel.delta;
                }else if(sfmlEvent == EventType::WindowResized){
                    bind->details.size.x == event.size.width;
                    bind->details.size.y = event.size.height;
                }else if(sfmlEvent == EventType::TextEntered){
                    bind->details.textEntered = event.text.unicode;
                }

                bind->eventCount++;
            }   
        }
    }
}

void EventManager::update(){
    if(!hasFocus) return;

    for(auto itr : bindings){
        Binding *bind = itr.second;

        for(auto eventItr : bind->events){
            switch(eventItr.first){
                case EventType::Keyboard:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(eventItr.second.code))){
                        if(bind->details.keyCode == -1){
                            bind->details.keyCode = eventItr.second.code;
                        }
                        bind->eventCount++;
                    }
                break;

                case(EventType::Mouse):
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button(eventItr.second.code))){
                        if(bind->details.keyCode == -1){
                            bind->details.keyCode = eventItr.second.code;
                        }
                        bind->eventCount++;
                    }
                break;
            }
        }

        /*
            Se todos os eventos presentes no Binding estão acontecendo, ou seja, se eventCount
            for igual o tamanho do vector de events, então chamamos o nosso callback;
        */

        if(bind->events.size() == bind->eventCount){
            auto callItr = callbacks.find(bind->name);

            if(callItr != callbacks.end()){
                callItr->second(&bind->details);
            }
        }

        bind->eventCount = 0;
        bind->details.clear();

    }

}

void EventManager::loadBindings(){
    std::string delimiter = ":";

    std::ifstream bindings("./keys.cfg", std::ios::in);

    if(!bindings.is_open()){
        std::cout << "Failed loading keys.cfg." << std::endl;
        return;
    }

    std::string line;

    while(std::getline(bindings, line)){
        std::stringstream keystream(line);
        std::string callbackName;

        keystream >> callbackName;

        Binding* bind = new Binding(callbackName);

        while(!keystream.eof()){
            std::string keyvalue;
            keystream >> keyvalue;

            int start = 0;
            int end = keyvalue.find(delimiter);

            if(end == std::string::npos){
                //Formato inválido do arquivo

                delete bind;
                bind = nullptr;
                break;
            }

            EventType type = EventType(
                std::stoi(keyvalue.substr(start,end-start))
            );

            int code = stoi(
                keyvalue.substr(
                    end+delimiter.length(), 
                    keyvalue.find(delimiter, end + delimiter.length())
                )
            );

            EventInfo eventInfo;

            eventInfo.code = code;

            bind->bindEvent(type, eventInfo);
        }

        if(!addBinding(bind)){ 
            delete bind; 
        }

        bind = nullptr;
    }

    bindings.close();
}