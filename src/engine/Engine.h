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

// this must be implemented in the game
void game_tick(float deltaTime);

struct SDL_Window;

class Engine {

public:

    Engine();
    ~Engine();

    bool init();
    void update();
    void quit();

private:

    //The window we'll be rendering to
    SDL_Window* mWindow;

};
