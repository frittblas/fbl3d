/*
*
*	Rock band manager
*
*	Game.cpp
*
*	The main game class.
*
*	Hans Strömquist 2025
*
*/

#include "../Engine/Engine.h"
#include "Game.h"
#include "Ecs/components.h"
#include "Ecs/Ecs.h"
#include "GameState/GameState.h"
#include "core/UserInput.h"
#include "core/GUI.h"
#include "core/Band.h"

Game::Game()
{
	init();
	Engine::log("Game created!");
}

Game::~Game()
{
	exit();
	Engine::log("Game destroyed!");
}

void test()
{
    Engine::log("Test callback!");
}

bool Game::init()
{
	Engine::mSpr.loadTexture(Engine::mRenderer, "assets/spritesheet.png");

	mEcs = new Ecs();
    mState = new GameState();
    mInput = new UserInput();
    mGui = new GUI(*this);
    mBand = new Band(*this);

	return true;
}

void Game::update()
{
 	mInput->tick(*this);	// get general user input (get specific input from the different states' tick())
	mState->tick(*this);	// update the current state
}

void Game::exit()
{
	delete mEcs;
    delete mState;
    delete mInput;
    delete mGui;
    delete mBand;
}
