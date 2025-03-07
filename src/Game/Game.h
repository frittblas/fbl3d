/*
*
*	Rock band manager
*
*	Game.h
*
*	The main game class.
*
*	Hans Strömquist 2025
*
*/

#pragma once

class Ecs;
class GameState;
class UserInput;
class GUI;
class Band;

class Game
{

public:

    Game();
    ~Game();

    void update();

    // pointers to all subsystems
    Ecs* mEcs;
    GameState* mState;
    UserInput* mInput;
    GUI* mGui;
    Band* mBand;

    // the game uses this internally
    static const int LogicalResW = 1920;
    static const int LogicalResH = 1080;

    // real resolution of each device
    static const int DeviceResW = LogicalResW;
    static const int DeviceResH = LogicalResH;

private:

    bool init();
    void exit();

};
