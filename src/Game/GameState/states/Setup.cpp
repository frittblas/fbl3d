/*
*
*	Rock band manager
*
*	Setup.cpp
*
*   Setup class implementation, takes care of the setup state.
*
*	Hans Strömquist 2025
*
*/

#include "../../../engine/Engine.h"
#include "../../Game.h"
#include "../../ecs/components.h"
#include "../../Ecs/Ecs.h"
#include "Setup.h"

Setup::Setup()
{

	Engine::log("Started Setup state.");

}

Setup::~Setup()
{

	Engine::log("Destroyed Setup state.");

}


// implement the virtual tick() function
void Setup::tick(Game& g)
{

	g.mEcs->mSpriteSys->update();

	if (rand() % 100 == 0) {
		Engine::log("Tick Setup.");
	}

}

void Setup::init(Game& g)
{

	entt::entity mPlayer, mPlayer2;

	mPlayer = g.mEcs->mReg.create();
	g.mEcs->mReg.emplace<PosComp>(mPlayer, 10.0f, 10.0f);
	g.mEcs->mReg.emplace<SpriteComp>(mPlayer, 0, 0.0f, 0.0f, 100.0f, 100.0f);
	g.mEcs->mReg.emplace<VelComp>(mPlayer, 20.0f, 20.0f);

	mPlayer2 = g.mEcs->mReg.create();
	g.mEcs->mReg.emplace<PosComp>(mPlayer2, 500.0f, 10.0f);
	g.mEcs->mReg.emplace<SpriteComp>(mPlayer2, 0, 100.0f, 0.0f, 100.0f, 100.0f);
	g.mEcs->mReg.emplace<VelComp>(mPlayer2, 20.0f, 20.0f);

	g.mEcs->mSpriteSys->init();

}
