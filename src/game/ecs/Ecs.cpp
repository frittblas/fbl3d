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

#include "../../engine/Engine.h"
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
