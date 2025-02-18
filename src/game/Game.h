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

#include "Ecs/Ecs.h"

class Game
{

public:

    Game();
    ~Game();

    void update();

    // pointers to all subsystems
    Ecs* mEcs;

    // the game uses this internally
    static const int LogicalResW = 960;
    static const int LogicalResH = 540;

    // real resolution of each device
    static const int DeviceResW = LogicalResW;
    static const int DeviceResH = LogicalResH;

private:

    bool init();
    void exit();

    entt::entity mPlayer, mPlayer2;

};
