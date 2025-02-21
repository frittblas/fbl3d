/*
*
*	fbl3d
*
*	Game.cpp
*
*	The main game class.
*
*	Hans Strömquist 2025
*
*/

#include "../engine/Engine.h"
#include "Game.h"
#include "Ecs/components.h"
#include "Ecs/Ecs.h"
#include "GameState/GameState.h"
#include "core/UserInput.h"

entt::entity mPlayer, mPlayer2;

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

bool Game::init()
{
	Engine::mSpr.loadTexture(Engine::mRenderer, "assets/spritesheet.bmp");

	mEcs = new Ecs();
    mState = new GameState();
    mInput = new UserInput();

	mPlayer = mEcs->mReg.create();
	mEcs->mReg.emplace<PosComp>(mPlayer, 10.0f, 10.0f);
	mEcs->mReg.emplace<SpriteComp>(mPlayer, 0, 0.0f, 0.0f, 100.0f, 100.0f);
	mEcs->mReg.emplace<VelComp>(mPlayer, 20.0f, 20.0f);

	mPlayer2 = mEcs->mReg.create();
	mEcs->mReg.emplace<PosComp>(mPlayer2, 500.0f, 10.0f);
	mEcs->mReg.emplace<SpriteComp>(mPlayer2, 0, 100.0f, 0.0f, 100.0f, 100.0f);
	mEcs->mReg.emplace<VelComp>(mPlayer2, 20.0f, 20.0f);

    mEcs->mSpriteSys->init();

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
}
