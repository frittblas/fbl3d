/*
*
*	fbl3d
*
*	SpriteSystem.h
*
*	The Sprite ECS system.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include <gaia/gaia.h>

using namespace gaia;

class SpriteSystem
{

public:
    SpriteSystem(ecs::World& w);
    ~SpriteSystem();

    ecs::SystemBuilder* mSpriteSys;
    ecs::Entity mSpriteSysEntity;

    int mSpriteSysCounter;

};
