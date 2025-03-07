/*
*
*	Rock band manager
*
*	GameState.hpp
*
*	GameState class header, FSM dealing with game states.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "IState.h"

class Game;

class GameState {

public:
    
    enum class StateType {
        // these will reload resources (sprites, text etc)
        Title,
        // these share resources
        Settings,
        Setup,
        Choice,
        Outcome
    };

    GameState();
    ~GameState();

    void  change(Game& g, StateType newState);
    StateType get();
    void tick(Game& g);

    void toTitle(Game& g);

private:
    StateType mState;               // enum holding the current state
    IState* mCurrentStateInstance;  // the actual instance of the current game state

};
