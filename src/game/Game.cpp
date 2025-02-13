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

	ecs::Entity mPlayer = mEcs->mWorld.add();
	mEcs->mWorld.add<PosComp>(mPlayer, { 0, 0 });
	mEcs->mWorld.add<VelComp>(mPlayer, { 20, 20 });
	mEcs->mWorld.add<SpriteComp>(mPlayer, { 0, 0, 0, 100, 100 });

	ecs::Entity mPlayer2 = mEcs->mWorld.add();
	mEcs->mWorld.add<PosComp>(mPlayer2, { 800, 0 });
	mEcs->mWorld.add<VelComp>(mPlayer2, { 20, 20 });
	mEcs->mWorld.add<SpriteComp>(mPlayer2, { 0, 0, 0, 100, 100 });

	uint32_t id = Engine::mSpr.create(0, 0, 100, 100, 0);
	uint32_t id2 = Engine::mSpr.create(100, 0, 100, 100, 0);

	mEcs->mWorld.set<SpriteComp>(mPlayer) = { id, 0, 0, 100, 100 };
	mEcs->mWorld.set<SpriteComp>(mPlayer2) = { id2, 0, 0, 100, 100 };

	//auto& spr = mEcs->mWorld.get<SpriteComp>(mPlayer);
    //spr.spriteId = id;

	return true;
}

void Game::update()
{

    mEcs->mWorld.update();

}

void Game::exit()
{

    delete mEcs;

}
