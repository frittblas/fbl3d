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
#include "Game.h"
#include "Ecs/components.h"
#include "Ecs/Ecs.h"
#include "GameState/GameState.h"
#include "core/UserInput.h"

entt::entity mPlayer, mPlayer2;

Game::Game()
{
	init();
	Engine::log("Game created!");
}

Game::~Game()
{
	exit();
	Engine::log("Game destroyed!");
}

void test()
{
    Engine::log("Test callback!");
}

bool Game::init()
{
	Engine::mSpr.loadTexture(Engine::mRenderer, "assets/spritesheet.bmp");

	mEcs = new Ecs();
    mState = new GameState();
    mInput = new UserInput();

	mPlayer = mEcs->mReg.create();
	mEcs->mReg.emplace<PosComp>(mPlayer, 10.0f, 10.0f);
	mEcs->mReg.emplace<SpriteComp>(mPlayer, 0, 0.0f, 0.0f, 100.0f, 100.0f);
	mEcs->mReg.emplace<VelComp>(mPlayer, 20.0f, 20.0f);

	mPlayer2 = mEcs->mReg.create();
	mEcs->mReg.emplace<PosComp>(mPlayer2, 500.0f, 10.0f);
	mEcs->mReg.emplace<SpriteComp>(mPlayer2, 0, 100.0f, 0.0f, 100.0f, 100.0f);
	mEcs->mReg.emplace<VelComp>(mPlayer2, 20.0f, 20.0f);

    mEcs->mSpriteSys->init();

	// test ui
	int i = Engine::mUI.createElement(UIType::CHECKBOX, 300, 100, "mr checkbox", nullptr);
	int id = Engine::mUI.createElement(UIType::TEXT_LABEL, 200, 100, "Testing longer string", nullptr);
    int id1 = Engine::mUI.createElement(UIType::BUTTON, 100, 100, "Hej", test);
	int id2 = Engine::mUI.createElement(UIType::BUTTON, 300, 100, "Hej2", test);
	int i2 = Engine::mUI.createElement(UIType::CHECKBOX, 300, 200, "mr checkbox2", nullptr);
	int id22 = Engine::mUI.createElement(UIType::TEXT_LABEL, 200, 200, "Testing longer string2", nullptr);
	int id11 = Engine::mUI.createElement(UIType::BUTTON, 100, 200, "Hej222222222222", test);
	int id23 = Engine::mUI.createElement(UIType::BUTTON, 300, 200, "Hej2333333333", test);
	int id3 = Engine::mUI.createWindow("Babys first window.");
    Engine::mUI.addElementToWindow(id3, id2);
	Engine::mUI.addElementToWindow(id3, id22);

	return true;
}

void Game::update()
{
 	mInput->tick(*this);	// get general user input (get specific input from the different states' tick())
	mState->tick(*this);	// update the current state
}

void Game::exit()
{
	delete mEcs;
    delete mState;
    delete mInput;
}
