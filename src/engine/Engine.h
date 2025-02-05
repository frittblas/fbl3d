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

struct SDL_Window;
struct SpriteManager;

class Engine {

public:

    static void initGame();
    static void gameLoop();
    static void quitGame();
    static void quit();

    static SpriteManager mSpr;

private:

    static bool fbl3dInit(int w, int h, int fps);
    static void update();
    static void updateGame();
    static void render();

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

    static bool mQuit;

};

