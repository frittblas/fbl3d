/*
*
*	fbl3d
*
*	Entry.cpp
*
*	The entry point of the game.
*
*	Hans Strömquist 2025
*
*/

#include "../engine/Engine.h"
#include "Game.h"

Game* gGame;

void Engine::initGame() {

	gGame = new Game();

}

void Engine::updateGame() {

	gGame->update();

}

void Engine::quitGame() {

	delete gGame;

}
