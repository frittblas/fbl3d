/*
*
*	Rock band manager
*
*	Settings.hpp
*
*	Settings class header, takes care of the settings screen.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "../IState.h"

class Game;

class Settings : public IState {

public:
    Settings();
    ~Settings();

    virtual void tick(Game& g) override;
};
