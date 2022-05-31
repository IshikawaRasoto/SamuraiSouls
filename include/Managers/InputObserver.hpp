#include "Patterns/Observer.hpp"
#include <string>

class InputObserver : public Patterns::Observer{
public:
    void update(std::string type, std::string key);
};