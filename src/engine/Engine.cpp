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

#include <SDL3/SDL.h>
#include <string>

#include <iostream>

Engine::Engine() {
	std::cout << "Initialized fbl3 engine." << std::endl;
}

Engine::~Engine() {
	std::cout << "Destroyed fbl3 engine." << std::endl;
}

bool Engine::init()
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

	SDL_Delay(3000);

    return success;

}

void Engine::update()
{

	std::cout << "Game loop running." << std::endl;

	float deltaTime = 0.0f;

	game_tick(deltaTime);

}

void Engine::quit()
{
    //Destroy window
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
	std::cout << "Quitting fbl3 engine." << std::endl;
}
