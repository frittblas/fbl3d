/*
*
*	fbl3d
*
*	UI.h
*
*	The UI manager.
*   Coordinates everything UI related.
*
*	Hans Strömquist 2025
*
*/

#pragma once

#include "../../vendor/common/ImGui/imgui.h"
#include "../../vendor/common/ImGui/imgui_impl_sdl3.h"
#include "../../vendor/common/ImGui/imgui_impl_sdlrenderer3.h"
#include <SDL3/SDL.h>

struct UI
{
	uint8_t layer;
};

class UIManager
{

public:
	
    UIManager();
    ~UIManager();

private:

	void init(SDL_Window* window, SDL_Renderer* renderer);
	void update();
	void processEvent(SDL_Event* e);
	void render(SDL_Renderer* renderer);
	void exit();

	ImGuiIO* mIo;

	friend class Engine;

};
