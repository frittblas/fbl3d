/*
*
*	fbl3d
*
*	Sprite.h
*
*	The sprite manager.
*   Coordinates everything sprite related.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include <cstdint>
#include <vector>

struct SpriteStruct {
	int x, y;
	int layer;
};

class Sprite {

public:
	
    Sprite();
    ~Sprite();
	
	SpriteStruct& get(int id);
	void sort();


private:
	std::vector<Sprite> mSpriteList;
	std::vector<Sprite> mIdList;

	uint32_t nextSpriteId = 0;

	void render();

};
