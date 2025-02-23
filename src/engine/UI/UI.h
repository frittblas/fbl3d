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

#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_sdl3.h>
#include <ImGui/imgui_impl_sdlrenderer3.h>
#include <SDL3/SDL.h>
#include <cstdint>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>

enum class UIType : uint8_t { TEXT_LABEL, BUTTON, CHECKBOX };

struct UIElement {
    uint8_t id;
    bool active;
    UIType type;
    float x, y;
    std::string text;
    std::function<void()> callback;
};

struct UIWindow {
    uint8_t id;
    bool active;
    std::string title;
    std::vector<UIElement> uiElements;
};

class UIManager
{

public:
	
    UIManager();
    ~UIManager();

    uint8_t createElement(UIType type, float x, float y, const std::string& text, std::function<void()> callback);
    uint8_t createWindow(const std::string& title);
    void addElementToWindow(int windowId, int elementId);
    void setElementActive(int elementId, bool active);
    void setWindowActive(int windowId, bool active);
    void clearAll();

private:

	void init(SDL_Window* window, SDL_Renderer* renderer);
	void update();
	void processEvent(SDL_Event* e);
	void render(SDL_Renderer* renderer);
	void exit();

	ImGuiIO* mIo;

    std::vector<UIElement> mUIElements;
    std::unordered_map<int, UIWindow> mWindows;
    uint8_t mNextElementId;
    uint8_t mNextWindowId;

	friend class Engine;

};
