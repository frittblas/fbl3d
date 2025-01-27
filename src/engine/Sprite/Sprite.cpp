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

Sprite::Sprite() {
	std::cout << "Initialized Sprite subsystem." << std::endl;
}

Sprite::~Sprite() {
	std::cout << "Destroyed Sprite subsystem." << std::endl;
}
