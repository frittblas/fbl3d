/*
*
*	Rock band manager
*
*	Settings.cpp
*
*   Settings class implementation, takes care of the settings screen.
*
*	Hans Strömquist 2025
*
*/

#include "../../../engine/Engine.h"
#include "../../Game.h"
#include "Settings.h"

Settings::Settings()
{

	Engine::log("Started Settings state.");

}

Settings::~Settings()
{

	Engine::log("Destroyed Settings state.");

}


// implement the virtual tick() function
void Settings::tick(Game& g)
{

	if (rand() % 100 == 0) {
		Engine::log("Tick Settings.");
	}

}
