#include "Patterns/State.hpp"
#include "Patterns/StateMachine.hpp"

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
