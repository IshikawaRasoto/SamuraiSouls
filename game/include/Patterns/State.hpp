#pragma once

namespace Patterns{

enum StateId{
    Unknown = -1,
    MainMenu,
    Leaderboard,
    Settings,
    FirstLevel,
    SecondLevel,
    Pause,
    NewGame,
    YouWin,
    GameOver
};

class StateMachine;

class State{
protected:

    StateId id;
    StateMachine *stateMachine;
    bool needReset;

public:

    State(const StateId id = StateId::Unknown, StateMachine *stateMachine = nullptr);
    virtual ~State();
    
    StateMachine* getStateMachine();
    StateId getId();

    bool getNeedReset();

    void setNeedReset(bool needReset);
    void setStateMachine(StateMachine* stateMachine);

    void changeCurrentState(Patterns::StateId state);

    virtual void update(const float dt) = 0;
    virtual void render() = 0; 
    virtual void reset();
};

}