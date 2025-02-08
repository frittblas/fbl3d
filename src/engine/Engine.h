/*
*
*	fbl3d
*
*	Engine.h
*
*	The main engine doing stuff.
*   Setup, game loop etc.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "Sprite/Sprite.h"
#include "UI/UI.h"

class Engine
{

public:

    static void initGame();     // called from main() in Engine.cpp
    static void loopEngine();   // also called from main()
    static void quitGame();	    // also called from main()
    static void quitEngine();   // also called from main()

    static bool initEngine(int w, int h, int fps);  // called from initGame() in Entry.cpp
    static void log(const char* msg, ...);

    static SDL_Renderer* mRenderer;

    static SpriteManager mSpr;
	static UIManager mUI;

private:

    static void updateEngine(); // called from loopEngine() in Engine.cpp
    static void updateGame();   // called from updateEngine() in Engine.cpp
    static void render2d();	    // called from loopEngine() in Engine.cpp

    //The window we'll be rendering to
    static SDL_Window* mWindow;

    // frame timing stuff
    static int mTargetFps;
    static int mTargetMsPerFrame;
    static int mTimeToWait;
    static int mMsPerFrame;
    static double mDeltaTime;
    static double mFps;
    static int mMsPrevFrame;

    static bool mLogMessages;
    static bool mQuit;

};

