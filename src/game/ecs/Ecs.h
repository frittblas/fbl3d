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

#include <gaia/gaia.h>
#include "systems/SpriteSystem.h"

using namespace gaia;

class Ecs
{

public:

    Ecs();
    ~Ecs();

    //static ecs::World mWorld;

    SpriteSystem* mSpriteSys;

private:

};
