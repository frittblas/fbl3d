/*
*
*	Rock band manager
*
*	UserInput.h
*
*	Input class header, takes care of all the user input.
*
*	Hans Strömquist 2025
*
*/

#pragma once

class Game;

class UserInput
{

public:

    const int mButtonDelay = 30;
    int mAccess;

    UserInput();
    ~UserInput();

    void tick(Game& g);

private:
    bool mIsFullscreen;

};
