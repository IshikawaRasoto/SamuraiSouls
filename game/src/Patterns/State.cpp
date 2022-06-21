#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"

using namespace Patterns;

State::State(const StateId id, StateMachine* stateMachine){
    this->id = id;
    this->stateMachine = stateMachine;
    needReset = false;
}

State::~State(){
    stateMachine = nullptr;
}

StateMachine* State::getStateMachine(){
    return stateMachine;
}

bool State::getNeedReset(){
    return needReset;
}

void State::setNeedReset(bool needReset){
    this->needReset = needReset;
}

void State::changeCurrentState(Patterns::StateId state){
    stateMachine->changeCurrentState(state);
}

StateId State::getId(){
    return id;
}

void State::setStateMachine(StateMachine* stateMachine){
    this->stateMachine = stateMachine;
}

void State::reset(){}
