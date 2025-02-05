/*
*
*	fbl3d
*
*	Sprite.cpp
*
*	The sprite manager.
*   Coordinates everything sprite related.
*
*	Hans Strömquist 2025
*
*/

#include "Sprite.h"
#include <iostream>
#include <algorithm>
#include <SDL3/SDL.h>

SpriteManager::SpriteManager() {
	mNextSpriteId = 0;
	std::cout << "Initialized Sprite subsystem." << std::endl;
}

SpriteManager::~SpriteManager() {
	std::cout << "Destroyed Sprite subsystem." << std::endl;
}

uint32_t SpriteManager::create(int x, int y, int w, int h, uint8_t layer)
{
	Sprite spr;
	spr.src.x = x;
	spr.src.y = y;
	spr.src.w = w;
	spr.src.h = h;
	spr.layer = layer;
	mSpriteList.push_back(spr);
	mIdToIndexMap[mNextSpriteId] = mSpriteList.size() - 1; // Map ID to index
	return mNextSpriteId++;
}

Sprite& SpriteManager::get(uint32_t id)
{
	return mSpriteList[id];
	//return mSpriteList[mIdToIndexMap[id]];
}

void SpriteManager::sort() {

	std::sort(mSpriteList.begin(), mSpriteList.end(), [](const Sprite& a, const Sprite& b) {
		return a.layer < b.layer;
		});


	for (size_t i = 0; i < mSpriteList.size(); ++i) {
		//mIdToIndexMap[mSpriteList[i].id] = i;
	}
}

void SpriteManager::clearAll()
{
	mSpriteList.clear();
	mIdToIndexMap.clear();
	mNextSpriteId = 0;
}

void SpriteManager::render()
{

	const int spriteCount = mSpriteList.size();

	// render sprites
	for (int i = 0; i < spriteCount; i++) {

	}

}
