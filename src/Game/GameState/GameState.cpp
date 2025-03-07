/*
*
*	Rock band manager
*
*	GameState.cpp
*
*	GameState class header, FSM dealing with game states.
*
*	Hans Strömquist 2025
*
*/

#include "../../Engine/Engine.h"
#include "../Game.h"
#include "GameState.h"
#include "states/Title.h"
#include "states/Settings.h"
#include "states/Setup.h"

GameState::GameState()
{
	mState = StateType::Title;
	mCurrentStateInstance = new Title();	// Start by default on title screen
}

GameState::~GameState()
{
	delete mCurrentStateInstance;
}

void GameState::change(Game& g, StateType newState)
{
	delete mCurrentStateInstance;	// delete the current state instance, calling the correct destructor

	// then set the new state and allocate resources for the new state
	switch (newState) {

		case StateType::Title:
			mCurrentStateInstance = new Title();
			break;
		case StateType::Setup:
			{
				Setup* s = new Setup();
				if (mState == StateType::Title) s->init(g);	// call the init function for new game init
                mCurrentStateInstance = s;
			}
			break;
		case StateType::Settings:
			mCurrentStateInstance = new Settings();
			break;
	}

	mState = newState;
}

GameState::StateType GameState::get()
{
	return mState;
}

void GameState::tick(Game& g)
{
	mCurrentStateInstance->tick(g);
}

void GameState::toTitle(Game& g)
{
}
