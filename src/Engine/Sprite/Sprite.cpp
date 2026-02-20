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
    mTexture = nullptr;
	mNextSpriteId = 0;
}

SpriteManager::~SpriteManager()
{
	clearAll();
	SDL_DestroyTexture(mTexture);
}

bool SpriteManager::loadTexture(SDL_Renderer* renderer, const char* path)
{
    if (!renderer) {
        SDL_Log("Invalid renderer provided to loadTexture");
        return false;
    }

    if (!path) {
        SDL_Log("Invalid path provided to loadTexture");
        return false;
    }

    // Load PNG into an SDL_Surface using SDL3 built-in loader
    SDL_Surface* surface = SDL_LoadPNG(path);
    if (!surface) {
        SDL_Log("Failed to load PNG %s: %s", path, SDL_GetError());
        return false;
    }

    // Create texture directly from surface
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!newTexture) {
        SDL_Log("Failed to create SDL texture: %s", SDL_GetError());
        SDL_DestroySurface(surface);
        return false;
    }

    SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);

    // Free the surface (no longer needed after texture creation)
    SDL_DestroySurface(surface);

    // Free previous texture if needed
    if (mTexture) {
        SDL_DestroyTexture(mTexture);
    }

    mTexture = newTexture;

    SDL_Log("Successfully loaded texture: %s", path);
    return true;
}

uint32_t SpriteManager::create(float x, float y, float w, float h, uint8_t layer)
{
	Sprite spr{
	{x, y, w, h}, // src
	{0, 0, w, h}, // dst
	layer,
    true // visible
	};

    uint32_t id = mNextSpriteId++;

	mSpriteList.push_back(spr);
    mDrawOrder.push_back(id);

	return id;
}

Sprite& SpriteManager::get(uint32_t id)
{
	return mSpriteList[id];
}

void SpriteManager::sort()
{
    std::sort(mDrawOrder.begin(), mDrawOrder.end(),
        [this](uint32_t a, uint32_t b)
        {
            return mSpriteList[a].layer < mSpriteList[b].layer;
        });
}

void SpriteManager::clearAll()
{
	mSpriteList.clear();
    mDrawOrder.clear();
	mNextSpriteId = 0;
}

void SpriteManager::render(SDL_Renderer* renderer)
{
    for (uint32_t id : mDrawOrder) {
        
        Sprite& spr = mSpriteList[id];

        if (spr.visible)
            SDL_RenderTextureRotated(renderer, mTexture, &spr.src, &spr.dst, 0, nullptr, SDL_FLIP_NONE);
    }
}
