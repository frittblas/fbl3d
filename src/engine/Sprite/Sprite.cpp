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

SpriteManager::SpriteManager()
{
	mNextSpriteId = 0;
	std::cout << "Initialized Sprite subsystem." << std::endl;
}

SpriteManager::~SpriteManager()
{
	clearAll();
	SDL_DestroyTexture(mTexture);
	std::cout << "Destroyed Sprite subsystem." << std::endl;
}

bool SpriteManager::loadTexture(SDL_Renderer* renderer, const char* path)
{

	SDL_Surface* surface = SDL_LoadBMP(path);

	if (!surface) {
		SDL_Log("Error loading sprite texture: %s", SDL_GetError());
		return false;
	}

	// 2. Set the color key (magenta)
	//Uint32 magentaColor = SDL_MapRGB(surface->format, 255, 0, 255);
	//SDL_SetSurfaceColorKey(surface, true, magentaColor);

	mTexture = SDL_CreateTextureFromSurface(renderer, surface);

	if (!mTexture) {
		SDL_Log("Error creating sprite texture from surface: %s", SDL_GetError());
		return false;
	}

	SDL_DestroySurface(surface);

	return true;

}

uint32_t SpriteManager::create(float x, float y, float w, float h, uint8_t layer)
{

	Sprite spr{
	{x, y, w, h}, // src
	{0, 0, w, h}, // dst
	layer
	};

	mSpriteList.push_back(spr);
	mIdToIndexMap[mNextSpriteId] = mSpriteList.size() - 1; //map id to index
	return mNextSpriteId++;
}

Sprite& SpriteManager::get(uint32_t id)
{
	return mSpriteList[id];
}

void SpriteManager::sort() {

}

void SpriteManager::clearAll()
{
	mSpriteList.clear();
	mIdToIndexMap.clear();
	mNextSpriteId = 0;
}

void SpriteManager::render(SDL_Renderer* renderer)
{

	const size_t spriteCount = mSpriteList.size();

	// render sprites
	for (int i = 0; i < spriteCount; i++) {
		SDL_RenderTextureRotated(renderer, mTexture, &mSpriteList[i].src,
			&mSpriteList[i].dst, 0, nullptr, SDL_FLIP_NONE);
	}

}
