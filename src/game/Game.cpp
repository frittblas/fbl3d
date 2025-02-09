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
#include <gaia/gaia.h>
#include "Game.h"

using namespace gaia;

Game::Game()
{
	Engine::log("Game created!");
	init();
}

Game::~Game()
{
	Engine::log("Game destroyed!");
	exit();
}

bool Game::init()
{
	Engine::log("Game init!");
	Engine::initEngine(1920, 1080, 60);
	Engine::mSpr.loadTexture(Engine::mRenderer, "assets/spritesheet.bmp");
	Engine::mSpr.create(0, 0, 100, 100, 0);
    ecs::World w;
	return true;
}

void Game::update()
{
	Engine::mSpr.get(0).dst.x += 10.0f * Engine::mDeltaTime;
	Engine::mSpr.get(0).dst.y += 10.0f * Engine::mDeltaTime;
}

void Game::exit()
{
}
