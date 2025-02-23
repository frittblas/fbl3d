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
	std::cout << "Initialized UI subsystem." << std::endl;
}

UIManager::~UIManager()
{
	std::cout << "Destroyed UI subsystem." << std::endl;
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
        // Handle font loading error
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
    UIElement elem = { mNextElementId++, type, x, y, true, text, callback };
    mUIElements.push_back(elem);
    return elem.id;
}

uint8_t UIManager::createWindow(const std::string& title)
{
    UIWindow window = { mNextWindowId++, title, {}, true };
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
        ImGui::SetNextWindowPos(ImVec2(elem.x, elem.y));
        size.x += 18;
        size.y += 16;
        ImGui::SetNextWindowSize(size);

        switch (elem.type) {
        case UIType::TEXT_LABEL:
        {

            ImGui::Begin(("txtWind_" + std::to_string(elem.id)).c_str(), nullptr, ImGuiWindowFlags_NoDecoration);
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
                break;
            }
        }
        ImGui::End();
    }

}

void UIManager::update2()
{
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();

    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / mIo->Framerate, mIo->Framerate);
        ImGui::End();
    }

    // 3. Show another simple window.
    if (show_another_window)
    {
        ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_another_window = false;
        ImGui::End();
    }

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
