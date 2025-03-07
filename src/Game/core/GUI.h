/*
*
*	Rock band manager
*
*	GUI.h
*
*	GUI class header, takes care of all UI elements and callbacks etc.
*
*	Hans Strömquist 2025
*
*/

#pragma once

class Game;

class GUI
{

public:

    GUI(Game& g);
    ~GUI();

    void tick(Game& g);

private:

    void init(Game& g);

    void startGame(Game& g);

    uint8_t mTitleTextLabel, mStartGameButton;

};
