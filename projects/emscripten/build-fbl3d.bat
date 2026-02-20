em++ ^
-I fbl3d/src/vendor/common ^
fbl3d/src/vendor/common/ImGui/imgui.cpp ^
fbl3d/src/vendor/common/ImGui/imgui_draw.cpp ^
fbl3d/src/vendor/common/ImGui/imgui_tables.cpp ^
fbl3d/src/vendor/common/ImGui/imgui_widgets.cpp ^
fbl3d/src/vendor/common/ImGui/imgui_impl_sdl3.cpp ^
fbl3d/src/vendor/common/ImGui/imgui_impl_sdlgpu3.cpp ^
fbl3d/src/vendor/common/ImGui/imgui_impl_sdlrenderer3.cpp ^
fbl3d/src/Engine/Engine.cpp ^
fbl3d/src/Engine/Sprite/Sprite.cpp ^
fbl3d/src/Engine/UI/UI.cpp ^
fbl3d/src/Game/core/GUI.cpp ^
fbl3d/src/Game/core/Band.cpp ^
fbl3d/src/Game/core/UserInput.cpp ^
fbl3d/src/Game/GameState/GameState.cpp ^
fbl3d/src/Game/GameState/states/Title.cpp ^
fbl3d/src/Game/GameState/states/Setup.cpp ^
fbl3d/src/Game/GameState/states/Settings.cpp ^
fbl3d/src/Game/ecs/Ecs.cpp ^
fbl3d/src/Game/ecs/systems/SpriteSystem.cpp ^
fbl3d/src/Game/Game.cpp ^
fbl3d/src/Game/Entry.cpp ^
-O2 ^
-sINITIAL_MEMORY=64MB ^
-sUSE_SDL=3 ^
--preload-file fbl3d/projects/emscripten/output/assets@/assets ^
-o fbl3d/projects/emscripten/output/fbl3d_test.html