/*
*
*	Rock band manager
*
*	UserInput.cpp
*
*	UserInput class implementation, takes care of all the user input.
*
*	Hans Strömquist 2025
*
*/

#include "../../Engine/Engine.h"
#include "UserInput.h"

UserInput::UserInput()
{

	mAccess = 0;
	mIsFullscreen = false;

	Engine::log("Initialized UserInput game subsystem.");

}

UserInput::~UserInput()
{

	Engine::log("Destroyed UserInput game subsystem.");

}

void UserInput::tick(Game& g)
{


}
