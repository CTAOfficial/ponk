#pragma once
#include "../RGBA.h"
#include <SDL3/SDL_render.h>
#include "../Vector2.h"

class Basic2D {
public:
	Basic2D(Vector2 pos, RGBA rgba) : rect{ (float)pos.X, (float)pos.Y, 50, 75 } {
		position = pos;
		colour = rgba;
	}

	Vector2 position;
	RGBA colour{ 0 ,0 ,0 ,0 };
	SDL_FRect rect;

	bool IsOverlapping(Basic2D& other);
};