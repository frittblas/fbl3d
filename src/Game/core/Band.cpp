/*
*
*	Rock band manager
*
*	Band.cpp
*
*	Band class implementation, takes care of all band related things (members etc.)
*
*	Hans Strömquist 2025
*
*/

#include "../../Engine/Engine.h"
#include "../Game.h"
#include "../GameState/GameState.h"
#include "Band.h"

Band::Band(Game& g)
{
	Engine::log("Initialized Band subsystem.");
}

Band::~Band()
{
	Engine::log("Destroyed Band subsystem.");
}

void Band::init(Game& g)
{

}

void Band::tick(Game& g)
{
}
