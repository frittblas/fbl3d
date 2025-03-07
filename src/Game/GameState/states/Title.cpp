/*
*
*	Rock band manager
*
*	Title.cpp
*
*   Title class implementation, takes care of the title screen.
*
*	Hans Strömquist 2025
*
*/

#include "../../../Engine/Engine.h"
#include "../../Game.h"
#include "Title.h"

Title::Title()
{

	Engine::log("Started Title state.");

}

Title::~Title()
{

	Engine::log("Destroyed Title state.");

}


// implement the virtual tick() function
void Title::tick(Game& g)
{

	if (rand() % 100 == 0) {
		Engine::log("Tick Title.");
	}

}
