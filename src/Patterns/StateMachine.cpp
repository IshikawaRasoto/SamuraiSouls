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
    lastState = currentState;
    currentState = state;

    std::cout << currentState << "\n";
}

void StateMachine::updateCurrentState(const float dt){
    states[currentState]->update(dt);
    renderCurrentState();
}

void StateMachine::renderCurrentState(){
    states[currentState]->render();
}