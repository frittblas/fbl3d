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

#include <entt/entt.hpp>

class SpriteSystem
{

public:
    SpriteSystem(entt::registry& reg) : mReg(reg) {}
    void init();
    void update();

private:
    entt::registry& mReg;

};
