/*
*
*	Rock band manager
*
*	IState.h
*
*	State interface, all the game states implement this.
*
*	Hans Strömquist 2025
*
*/

#pragma once

class Game;

class IState
{

public:
    virtual ~IState() = default; // virtual destructor, so the destructor gets called of the derived classes
    virtual void tick(Game& g) = 0;

};
