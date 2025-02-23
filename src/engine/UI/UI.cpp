/*
*
*	fbl3d
*
*	UI.cpp
*
*	The UI manager.
*   Coordinates everything UI related.
*
*	Hans Strömquist 2025
*
*/

#include "UI.h"
#include <iostream>

// Our state
bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}


void UIManager::init(SDL_Window* window, SDL_Renderer* renderer)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
    mIo = &ImGui::GetIO();
	mIo->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	mIo->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImFont* myFont = mIo->Fonts->AddFontFromFileTTF("assets/font/garamond.ttf", 30.0f);

    if (myFont == nullptr) {
        // NOTE: Handle font loading error nicer, return something
        std::cerr << "Failed to load font!" << std::endl;
    }

    mIo->FontDefault = myFont;

    ImGuiStyle& style = ImGui::GetStyle();

    // Button colors (orange)
    style.Colors[ImGuiCol_Button] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f); // Idle button color
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.9f, 0.5f, 0.1f, 1.0f); // Hovered button color
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.7f, 0.3f, 0.0f, 1.0f); // Active button color

    // Header colors (orange)
    style.Colors[ImGuiCol_Header] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f); // Idle header color
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.9f, 0.5f, 0.1f, 1.0f); // Hovered header color
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.7f, 0.3f, 0.0f, 1.0f); // Active header color

    // Slider grab colors (orange)
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.9f, 0.5f, 0.1f, 1.0f); // Idle slider grab
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.7f, 0.3f, 0.0f, 1.0f); // Active slider grab

    // Checkmark color (orange)
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.9f, 0.5f, 0.1f, 1.0f);

    // Frame background colors (orange)
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f); // Idle frame background
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.9f, 0.5f, 0.1f, 1.0f); // Hovered frame background
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.7f, 0.3f, 0.0f, 1.0f); // Active frame background

    // Tab colors (orange)
    style.Colors[ImGuiCol_Tab] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f); // Idle tab color
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.9f, 0.5f, 0.1f, 1.0f); // Hovered tab color
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.7f, 0.3f, 0.0f, 1.0f); // Active tab color

    // Window title bar colors (orange)
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.7f, 0.3f, 0.0f, 1.0f); // Idle title bar color
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f); // Active title bar color

	//ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);

    mNextElementId = 0;
    mNextWindowId = 0;

#ifdef __EMSCRIPTEN__
	io.IniFilename = nullptr;
#endif

}

uint8_t UIManager::createElement(UIType type, float x, float y, const std::string& text, std::function<void()> callback)
{
    UIElement elem = { mNextElementId++, true, type, x, y, text, callback };
    mUIElements.push_back(elem);
    return elem.id;
}

uint8_t UIManager::createWindow(const std::string& title)
{
    UIWindow window = { mNextWindowId++, true, title, {} };
    mWindows[window.id] = window;
    return window.id;
}

void UIManager::addElementToWindow(int windowId, int elementId)
{
    auto it = mWindows.find(windowId);
    if (it != mWindows.end()) {
        auto elemIt = std::find_if(mUIElements.begin(), mUIElements.end(), [&](const UIElement& elem) {
            return elem.id == elementId;
            });

        if (elemIt != mUIElements.end()) {
            it->second.uiElements.push_back(*elemIt);
            mUIElements.erase(elemIt);
        }
    }
}

void UIManager::setElementActive(int elementId, bool active) {
    for (auto& elem : mUIElements) {
        if (elem.id == elementId) {
            elem.active = active;
            return;
        }
    }
    for (auto& [_, window] : mWindows) {
        for (auto& elem : window.uiElements) {
            if (elem.id == elementId) {
                elem.active = active;
                return;
            }
        }
    }
}

void UIManager::setWindowActive(int windowId, bool active) {
    auto it = mWindows.find(windowId);
    if (it != mWindows.end()) {
        it->second.active = active;
    }
}

void UIManager::clearAll() {
    mUIElements.clear();
    for (auto& [_, window] : mWindows) {
        window.uiElements.clear();
    }
    mWindows.clear();
    mNextElementId = 0;
    mNextWindowId = 0;
}

void UIManager::update() {

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    for (auto& elem : mUIElements) {
        if (!elem.active) continue;

        ImVec2 size = ImGui::CalcTextSize(elem.text.c_str());
        size.x += 18;
        size.y += 16;
        ImGui::SetNextWindowSize(size);
        ImGui::SetNextWindowPos(ImVec2(elem.x, elem.y));

        switch (elem.type) {
        case UIType::TEXT_LABEL:
        {
            ImGui::Begin(("txtWind_" + std::to_string(elem.id)).c_str(), nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs);
            ImGui::SetCursorPos(ImVec2(5, 5)); // center button inside the window
            ImGui::Text("%s", elem.text.c_str());
            ImGui::End();
        }
        break;
        case UIType::BUTTON:
        {
            ImGui::Begin(("btnWind_" + std::to_string(elem.id)).c_str(), nullptr, ImGuiWindowFlags_NoDecoration);
            ImGui::SetCursorPos(ImVec2(5, 5));
            if (ImGui::Button(elem.text.c_str())) {
                if (elem.callback) elem.callback();
            }
            ImGui::End();
        }
        break;
        }
    }

    for (auto& [_, window] : mWindows) {
        if (!window.active) continue;
        ImGui::Begin(window.title.c_str());

        for (auto& elem : window.uiElements) {
            if (!elem.active) continue;
            ImGui::SetCursorPos(ImVec2(elem.x, elem.y));
            switch (elem.type) {
            case UIType::TEXT_LABEL:
                ImGui::Text("%s", elem.text.c_str());
                break;
            case UIType::BUTTON:
                if (ImGui::Button(elem.text.c_str())) {
                    if (elem.callback) elem.callback();
                }
                break;
            case UIType::CHECKBOX:
                static bool checkboxState = false;
                ImGui::Checkbox(elem.text.c_str(), &checkboxState);
                //ImGui::SameLine();
                break;
            }
        }
        ImGui::End();
    }

    ImGui::Begin("Fps");
    ImGui::Text("App average: %.3f ms/frame (%.1f FPS)", 1000.0f / mIo->Framerate, mIo->Framerate);
    ImGui::End();

}

void UIManager::processEvent(SDL_Event* e)
{
    ImGui_ImplSDL3_ProcessEvent(e);
}

void UIManager::render(SDL_Renderer* renderer)
{
	ImGui::Render();
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
}

void UIManager::exit()
{
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();
}
