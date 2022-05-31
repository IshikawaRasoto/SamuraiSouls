#pragma once

#include <string>

namespace Patterns{
template<typename T>

class Observer{
public:
    virtual void update(T *subject) = 0;
};

}
