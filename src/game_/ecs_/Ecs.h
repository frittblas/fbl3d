/*
*
*	fbl3d
*
*	Ecs.h
*
*	The Ecs manager class. Keeps track of systems etc
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include <entt/entt.hpp>
#include "systems/SpriteSystem.h"

class Ecs
{

public:

    Ecs();
    ~Ecs();

    entt::registry mReg;

    SpriteSystem* mSpriteSys;

private:

};
