#include "Managers/Control/LevelControl.hpp"
#include "Levels/Level.hpp"

using namespace Managers::Control;

LevelControl::LevelControl(Levels::Level *level,std::string pause):
    keys(pause)
{
    this->level = level;
}

LevelControl::~LevelControl(){
    this->level = nullptr;
}

Levels::Level *LevelControl::getLevel(){
    return level;
}

void LevelControl::setLevel(Levels::Level *level){
    this->level = level;
}

void LevelControl::update(InputManager *subject){
    if(!level) return;

    std::string event = subject->getCurrentEvent();
    std::string key = subject->getCurrentKey();

    if(key == keys.pause){
        level->handlePause();
    }
}

