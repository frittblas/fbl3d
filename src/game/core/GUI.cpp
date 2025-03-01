/*
*
*	Rock band manager
*
*	GUI.hpp
*
*	GUI class implementation, takes care of all UI elements and callbacks etc.
*
*	Hans Strömquist 2025
*
*/

#include "../../engine/Engine.h"
#include "../Game.h"
#include "../GameState/GameState.h"
#include "GUI.h"

GUI::GUI(Game& g)
{
    init(g);
	Engine::log("Initialized GUI subsystem.");
}

GUI::~GUI()
{
    Engine::mUI.clearAll();
	Engine::log("Destroyed GUI subsystem.");
}

void GUI::init(Game& g)
{

    mTitleTextLabel = Engine::mUI.createElement(UIType::TEXT_LABEL, Game::LogicalResW / 2 - 100, Game::LogicalResH / 4, "Rock band manager", nullptr);
    mStartGameButton = Engine::mUI.createElement(UIType::BUTTON, Game::LogicalResW / 2 - 50, Game::LogicalResH / 2, "Start game", [this, &g]() {
            this->startGame(g);
        });

}

void GUI::tick(Game& g)
{
}

void GUI::startGame(Game& g)
{
    Engine::mUI.setElementActive(mTitleTextLabel, false);
    Engine::mUI.setElementActive(mStartGameButton, false);
    g.mState->change(g, GameState::StateType::Setup);
}
