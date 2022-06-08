#include "Patterns/State.hpp"

using namespace Patterns;

State::State(const StateId id, StateMachine* stateMachine){
    this->id = id;
    this->stateMachine = stateMachine;
}

State::~State(){
    stateMachine = nullptr;
}

StateMachine* State::getStateMachine(){
    return stateMachine;
}

StateId State::getId(){
    return id;
}

void State::setStateMachine(StateMachine* stateMachine){
    this->stateMachine = stateMachine;
}

void State::reset(){}
