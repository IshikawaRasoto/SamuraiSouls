#include <map>
#include <iostream>

using namespace std;

class EventListerner{

public:
    virtual void update(){
        cout << "EventListener updated.\n";
    }
};

class Listener1 : public EventListerner{

public:
    void update(){
        cout << "Listener1 updated.\n";
    }
};

class Listener2 : public EventListerner{

public:
    void update(){
        cout << "Listener2 updated.\n";
    }
};


enum class EventType{
    keyPressed = 0,
    keyReleased
};

int main(){

    multimap<EventType, EventListerner*> listeners;

    Listener1 listener1;
    Listener2 listener2;

    listeners.insert(pair<EventType, EventListerner*>(EventType::keyPressed, &listener1));
    listeners.insert(pair<EventType, EventListerner*>(EventType::keyPressed, &listener2));

    using ListenersIterator = multimap<EventType, EventListerner*>::iterator;

    pair<ListenersIterator, ListenersIterator> result = listeners.equal_range(EventType::keyPressed);

    for(ListenersIterator it = result.first; it != result.second; it++){
        it->second->update();
    }

    return 0;
}