/*
*
*	fbl3d
*
*	Main.cpp
*
*	The entry point of the game.
*
*	Hans Strömquist 2025
*
*/

#include "../engine/Engine.h"
#include <iostream>

int main(int argc, char* argv[]) {
	
	Engine engine;

	engine.init();
	engine.update();
	engine.quit();

	return 0;

}

void game_tick(float deltaTime) {
	std::cout << "Called game tick." << std::endl;
}
