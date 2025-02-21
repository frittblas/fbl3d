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
