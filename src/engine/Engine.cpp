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
SDL_Renderer* Engine::mRenderer;

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
	Engine::loopEngine();
    Engine::quitGame();
    Engine::quitEngine();

    return 0;

}

bool Engine::initEngine(int w, int h, int fps)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow("SDL3 Tutorial: Hello SDL3", 960, 540, 0);
    if(mWindow == nullptr) {
        SDL_Log("Window could not be created! SDL error: %s\n", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, nullptr);
    if (mRenderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL error: %s\n", SDL_GetError());
		return false;
    }

    SDL_Log("SDL3 working! :)\n");

    mTargetFps = fps;
    mTargetMsPerFrame = 1000 / mTargetFps;

    mQuit = false;

    return true;

}

void Engine::loopEngine()
{

	SDL_Event e;

    SDL_Log("Game loop running!");

    while (mQuit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                mQuit = true;
            }
        }

        updateEngine();
		render2d();

    }

}

void Engine::updateEngine()
{

    updateGame();

    // If we are too fast, waste some time until we reach the mTargetMsPerFrame
    mTimeToWait = static_cast<int>(mTargetMsPerFrame - (SDL_GetTicks() - mMsPrevFrame));
    if (mTimeToWait > 0 && mTimeToWait <= mTargetMsPerFrame) {
        SDL_Delay(mTimeToWait);
    }

    // The difference in ticks since the last frame, converted to seconds
    mDeltaTime = (SDL_GetTicks() - mMsPrevFrame) / 1000.0;

    // Store how many ms a whole frame took
    mMsPerFrame = static_cast<int>(SDL_GetTicks() - mMsPrevFrame);

    // Store the "previous" frame time
    mMsPrevFrame = static_cast<int>(SDL_GetTicks());

    // Calculate frames per second
    mFps = 1000.0 / mMsPerFrame;

    if (rand() % 30 == 0) {
        SDL_Log("time to wait = %d, msPerFrame = %d, FPS = %f", mTimeToWait, mMsPerFrame, mFps);
    }

}

void Engine::render2d() {

	SDL_RenderClear(mRenderer);
	mSpr.render(mRenderer); // Render all sprites to backbuffer (private function friend class)
	SDL_RenderPresent(mRenderer);

}

void Engine::quitEngine()
{
    SDL_Log("Quitting fbl3b engine.");
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

// public fbl3d api starts here

void Engine::log(const char* msg, ...)
{
    va_list args;
    char text_buf[256];
    va_start(args, msg);
#ifdef _MSC_VER
    vsprintf_s(text_buf, 256, msg, args);
#else
    vsprintf(text_buf, msg, args);
#endif
    va_end(args);

    SDL_Log("%s", text_buf);
}
