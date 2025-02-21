/*
*
*	fbl3d
*
*	SpriteSystem.cpp
*
*	The Sprite ECS system.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "../../engine/Engine.h"
#include "../components.h"
#include "SpriteSystem.h"

void SpriteSystem::init()
{
    auto view = mReg.view<PosComp, SpriteComp, VelComp>();

    view.each([](const entt::entity entity, const PosComp& pos, SpriteComp& spr, const VelComp& vel) {
        
        spr.spriteId = Engine::mSpr.create(spr.x, spr.y, spr.w, spr.h, 0);
        
        });

}

void SpriteSystem::update()
{

    auto view = mReg.view<PosComp, SpriteComp, VelComp>();

    view.each([](const entt::entity entity, PosComp& pos, const SpriteComp& spr, const VelComp& vel) {

        pos.x += vel.x * Engine::mDeltaTime;
        pos.y += vel.y * Engine::mDeltaTime;

        Engine::mSpr.get(spr.spriteId).dst.x = pos.x;
        Engine::mSpr.get(spr.spriteId).dst.y = pos.y;

        });

}
