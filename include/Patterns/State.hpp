#pragma once

namespace Patterns{

enum StateId{
    Unknown = -1,
    MainMenu,
    Leaderboard,
    Settings,
    FirstLevel,
    SecondLevel,
    ThirdLevel,
    Pause,
    GameOver
};

class StateMachine;

class State{
protected:

    StateId id;
    StateMachine *stateMachine;

public:

    State(const StateId id = StateId::Unknown, StateMachine *stateMachine = nullptr);
    virtual ~State();
    
    StateMachine* getStateMachine();
    StateId getId();

    void setStateMachine(StateMachine* stateMachine);

    virtual void update(const float dt) = 0;
    virtual void render() = 0; 
    virtual void reset();
};

}