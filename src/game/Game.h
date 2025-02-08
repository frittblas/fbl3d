/*
*
*	fbl3d
*
*	Game.h
*
*	The main game class.
*
*	Hans Strömquist 2025
*
*/

#pragma once

class Game
{

public:

    Game();
    ~Game();

    void update();

    // the game uses this internally
    static const int LogicalResW = 960;
    static const int LogicalResH = 540;

    // real resolution of each device
    static const int DeviceResW = LogicalResW;
    static const int DeviceResH = LogicalResH;

private:

    bool init();
    void exit();

};
