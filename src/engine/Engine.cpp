/*
*
*	fbl3d
*
*	Engine.cpp
*
*	The main engine doing stuff.
*   Setup, game loop etc.
*
*	Hans Strömquist 2025
*
*/

#include "Engine.h"
#include "Sprite/Sprite.h"
#include <SDL3/SDL.h>

// definitions
SDL_Window* Engine::mWindow;

// managers
SpriteManager Engine::mSpr;

// frame timing stuff
int Engine::mTargetFps;
int Engine::mTargetMsPerFrame;
int Engine::mTimeToWait;
int Engine::mMsPrevFrame;
double Engine::mDeltaTime;
double Engine::mFps;
int Engine::mMsPerFrame;

bool Engine::mQuit;

int main(int argc, char* argv[]) {


    Engine::initGame();
	Engine::gameLoop();
    Engine::quitGame();
    Engine::quit();

    return 0;

}

bool Engine::fbl3dInit(int w, int h, int fps)
{

    bool success = true;

    //Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        mWindow = SDL_CreateWindow("SDL3 Tutorial: Hello SDL3", 960, 540, 0);
        if(mWindow == nullptr)
        {
            SDL_Log("Window could not be created! SDL error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            SDL_Log("SDL3 working! :)\n");
        }
    }

    mTargetFps = fps;
    mTargetMsPerFrame = 1000 / mTargetFps;

    mQuit = false;

    return success;

}

void Engine::gameLoop()
{
	// Event handler
	SDL_Event e;

    SDL_Log("Game loop running!");

    //The main loop
    while (mQuit == false)
    {
        //Get event data
        while (SDL_PollEvent(&e))
        {
            //If event is quit type
            if (e.type == SDL_EVENT_QUIT)
            {
                //End the main loop
                mQuit = true;
            }
        }

        update();
		render();

    }

}

void Engine::update()
{

    updateGame();

    // frame timing

    // If we are too fast, waste some time until we reach the mTargetMsPerFrame
    mTimeToWait = mTargetMsPerFrame - (SDL_GetTicks() - mMsPrevFrame);
    if (mTimeToWait > 0 && mTimeToWait <= mTargetMsPerFrame) {
        SDL_Delay(mTimeToWait);
    }

    // The difference in ticks since the last frame, converted to seconds
    mDeltaTime = (SDL_GetTicks() - mMsPrevFrame) / 1000.0;

    // Store how many ms a whole frame took
    mMsPerFrame = SDL_GetTicks() - mMsPrevFrame;

    // Store the "previous" frame time
    mMsPrevFrame = SDL_GetTicks();

    // Calculate frames per second
    mFps = 1000.0 / mMsPerFrame;

    if (rand() % 30 == 0) {
        SDL_Log("time to wait = %d, msPerFrame = %d, FPS = %f", mTimeToWait, mMsPerFrame, mFps);
    }

}

void Engine::render() {

}

void Engine::quit()
{

    SDL_Log("Quitting fbl3 engine.");

    //Destroy window
	SDL_DestroyWindow(mWindow);
    mWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();

}
