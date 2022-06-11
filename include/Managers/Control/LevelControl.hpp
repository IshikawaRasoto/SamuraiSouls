#pragma once

#include <string>

#include "LevelKeys.hpp"
#include "Patterns/Observer.hpp"
#include "Managers/Input.hpp"

namespace Levels{
    class Level;
}

namespace Managers{
namespace Control{
class LevelControl : public Observer<Managers::InputManager>{
private:
    Levels::Level *level;
    LevelKeys keys;

public:
    LevelControl(
        Levels::Level *level = nullptr, 
        std::string pause = "Esc"
    );

    ~LevelControl();

    Levels::Level* getLevel();
    void setLevel(Levels::Level *level);

    void update(Managers::InputManager *subject);
};
}
}

