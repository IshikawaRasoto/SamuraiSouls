#include <string>
#include <SFML/Window/Event.hpp>
#include "Patterns/Observer.hpp"

namespace Managers{

class EventObserver : public Patterns::Observer{
public:
    void update(std::string type);
    void update(std::string type, std::string key);
};

}

