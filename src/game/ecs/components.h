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
    int spriteId;
	int texX, texY; // where on the sheet is the sprite located?
	int w, h;
};
