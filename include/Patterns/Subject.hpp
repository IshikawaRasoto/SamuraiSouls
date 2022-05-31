#pragma once

#include <map>
#include <string>
#include <map>

#include "Observer.hpp"

namespace Patterns{
template<typename T>
class Subject{ 
protected:
    std::multimap<std::string, Observer<T>*> observers;
public:
    virtual void subscribe(std::string type, Observer<T> *observer) = 0;
    virtual void unsubscribe(std::string type, Observer<T> *observer) = 0;
    virtual void notify() = 0;
};

}

