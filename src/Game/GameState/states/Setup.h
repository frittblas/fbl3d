/*
*
*	Rock band manager
*
*	Setup.h
*
*	Setup class header, takes care of the setup state.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "../IState.h"

class Game;

class Setup : public IState
{

public:
    Setup();
    ~Setup();

    void init(Game& g);

    virtual void tick(Game& g) override;

private:


};
