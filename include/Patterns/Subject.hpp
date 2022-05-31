#include <map>
#include <string>
#include "Observer.hpp"

namespace Patterns{

class Subject{ 
public:
    virtual void subscribe(std::string type, Observer* observer) = 0;
    virtual void unsubscribe(std::string type, Observer* observer) = 0;
    virtual void notify(std::string type) = 0;
};

}

