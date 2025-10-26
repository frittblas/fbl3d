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

struct StatWindow
{
    uint8_t toggleBtn, window;
    uint8_t sklLbl, artLbl, chrmLbl, drvLbl, stressLbl;
    uint8_t sklBar, artBar, chrmBar, drvBar, stressBar;
};

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
    std::vector<StatWindow> mStatWindows;

};
