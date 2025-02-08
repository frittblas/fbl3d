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
#include <unordered_map>
#include <SDL3/SDL.h>


struct Sprite
{
	SDL_FRect src, dst;	// src rect is image on texture, dst rect is where on screen
	uint8_t layer;
};

class SpriteManager
{

public:
	
    SpriteManager();
    ~SpriteManager();
	
	bool loadTexture(SDL_Renderer* renderer, const char* path);
	uint32_t create(int x, int y, int w, int h, uint8_t layer);
	Sprite& get(uint32_t id);
	void sort();
	void clearAll();

private:

	void render(SDL_Renderer* renderer);

	std::vector<Sprite> mSpriteList;
	std::unordered_map<uint32_t, size_t> mIdToIndexMap;

	SDL_Texture* mTexture;

	uint32_t mNextSpriteId;

	friend class Engine;

};
