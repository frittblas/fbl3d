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
#include "../../Game/Ecs/components.h"
#include "../../Game/Ecs/Ecs.h"
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

    entt::entity tmpMember;

	tmpMember = g.mEcs->mReg.create();
	g.mEcs->mReg.emplace<PosComp>(tmpMember, 600.0f, 200.0f);
	g.mEcs->mReg.emplace<SpriteComp>(tmpMember, 0, 0.0f, 0.0f, 100.0f, 250.0f);
	g.mEcs->mReg.emplace<VelComp>(tmpMember, 20.0f, 20.0f);

    mLineUp.push_back(tmpMember);

	tmpMember = g.mEcs->mReg.create();
	g.mEcs->mReg.emplace<PosComp>(tmpMember, 800.0f, 200.0f);
	g.mEcs->mReg.emplace<SpriteComp>(tmpMember, 0, 100.0f, 0.0f, 100.0f, 250.0f);
	g.mEcs->mReg.emplace<VelComp>(tmpMember, 20.0f, 20.0f);

	mLineUp.push_back(tmpMember);

	tmpMember = g.mEcs->mReg.create();
	g.mEcs->mReg.emplace<PosComp>(tmpMember, 1000.0f, 200.0f);
	g.mEcs->mReg.emplace<SpriteComp>(tmpMember, 0, 200.0f, 0.0f, 100.0f, 250.0f);
	g.mEcs->mReg.emplace<VelComp>(tmpMember, 20.0f, 20.0f);

	mLineUp.push_back(tmpMember);

	tmpMember = g.mEcs->mReg.create();
	g.mEcs->mReg.emplace<PosComp>(tmpMember, 1200.0f, 200.0f);
	g.mEcs->mReg.emplace<SpriteComp>(tmpMember, 0, 300.0f, 0.0f, 100.0f, 250.0f);
	g.mEcs->mReg.emplace<VelComp>(tmpMember, 20.0f, 20.0f);

	mLineUp.push_back(tmpMember);

}

void Band::tick(Game& g)
{
}
