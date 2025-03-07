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

#include "../../../Engine/Engine.h"
#include "../../Game.h"
#include "../../Ecs/components.h"
#include "../../Ecs/Ecs.h"
#include "../../Game/core/Band.h"
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
    g.mBand->init(g);
	g.mEcs->mSpriteSys->init();
}
