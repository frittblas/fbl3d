/*
*
*	fbl3d
*
*	Ecs.cpp
*
*	The Ecs manager class. Keeps track of systems etc
*
*	Hans Strömquist 2025
*
*/

#include "../../Engine/Engine.h"
#include "Ecs.h"
#include "components.h"

Ecs::Ecs()
{
    mSpriteSys = new SpriteSystem(mReg);
}

Ecs::~Ecs()
{
    delete mSpriteSys;
}
