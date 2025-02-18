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
#include "Ecs/components.h"
#include "Game.h"

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
	Engine::initEngine(1920, 1080, 60);
	Engine::mSpr.loadTexture(Engine::mRenderer, "assets/spritesheet.bmp");

    mEcs = new Ecs();

	mPlayer = mEcs->mReg.create();
	mEcs->mReg.emplace<PosComp>(mPlayer, 10.0f, 10.0f);
	mEcs->mReg.emplace<SpriteComp>(mPlayer, 0, 0, 0, 100, 100);
	mEcs->mReg.emplace<VelComp>(mPlayer, 20.0f, 20.0f);

	mPlayer2 = mEcs->mReg.create();
	mEcs->mReg.emplace<PosComp>(mPlayer2, 500.0f, 10.0f);
	mEcs->mReg.emplace<SpriteComp>(mPlayer2, 0, 100, 0, 100, 100);
	mEcs->mReg.emplace<VelComp>(mPlayer2, 20.0f, 20.0f);

    mEcs->mSpriteSys->init();

	return true;
}

void Game::update()
{

    mEcs->mSpriteSys->update();

}

void Game::exit()
{

    delete mEcs;

}
