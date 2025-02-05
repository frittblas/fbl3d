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

struct SDL_Rect;

struct Sprite {
	SDL_Rect src, dst;	// src rect is image on texture, dst rect is where on screen
	uint8_t layer;
};

class SpriteManager {

public:
	
    SpriteManager();
    ~SpriteManager();
	
	uint32_t create(int x, int y, int w, int h, uint8_t layer);
	Sprite& get(uint32_t id);
	void sort();
	void clearAll();


private:

	void render();

	std::vector<Sprite> mSpriteList;
	std::unordered_map<uint32_t, size_t> mIdToIndexMap;

	uint32_t mNextSpriteId;

};
