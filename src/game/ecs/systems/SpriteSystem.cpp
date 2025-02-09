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
#include "../Ecs.h"
#include "../components.h"
#include "SpriteSystem.h"

SpriteSystem::SpriteSystem()
{
    int sys1_cnt = 0;

    ecs::World mWorld1;

    mSpriteSys = new ecs::SystemBuilder(mWorld1.system()
        // System considers all entities with Position and Velocity components.
        // Position is mutable.
        .all<PosComp&, SpriteComp>()
        // Logic to execute every time the system is invoked.
        .on_each([&sys1_cnt](PosComp& p, const VelComp& v, const SpriteComp& s) {

            p.x += v.x * Engine::mDeltaTime;
            p.y += v.y * Engine::mDeltaTime;

            }));
}

SpriteSystem::~SpriteSystem()
{
}
