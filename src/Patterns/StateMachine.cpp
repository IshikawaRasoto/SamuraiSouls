#include "Patterns/StateMachine.hpp"

#include <iostream>

using namespace Patterns;

StateMachine::StateMachine(){
    currentState = StateId::Unknown;
    lastState = StateId::Unknown;
    states.clear();
}

StateMachine::~StateMachine(){
    states.clear();
}

StateId StateMachine::getCurrentState(){
    return currentState;
}

StateId StateMachine::getLastState(){
    return lastState;
}

void StateMachine::changeCurrentState(const StateId state){
    if(state == StateId::MainMenu && lastState){
        states[lastState]->reset();
        states[lastState]->setNeedReset(false);
    }

    lastState = currentState;
    currentState = state;

    if(states[currentState]->getNeedReset()){
        states[currentState]->reset();
        states[currentState]->setNeedReset(false);
    }
}

void StateMachine::updateCurrentState(const float dt){
    states[currentState]->update(dt);
    renderCurrentState();
}

void StateMachine::renderCurrentState(){
    states[currentState]->render();
}

