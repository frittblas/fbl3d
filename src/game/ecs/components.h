/*
*
*	fbl3d
*
*	components.h
*
*	All the ECS components.
*
*	Hans Strömquist 2025
*
*/

#pragma once

struct PosComp
{
	float x, y;
};

struct VelComp
{
	float x, y;
};

struct SpriteComp
{
    uint32_t spriteId;
	uint16_t texX, texY; // where on the sheet is the sprite located?
	uint16_t w, h;
};
