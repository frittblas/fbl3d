/*
*
*	Rock band manager
*
*	Title.hpp
*
*	Title class header, takes care of the title screen.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "../IState.h"

class Game;

class Title : public IState
{

public:
    Title();
    ~Title();

    virtual void tick(Game& g) override;

};
