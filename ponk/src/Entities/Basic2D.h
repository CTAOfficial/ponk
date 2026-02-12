#pragma once
#include "../RGBA.h"
#include <SDL3/SDL_render.h>
#include "../Vector2.h"

class Game;

class Basic2D {
public:
	Basic2D(Vector2 pos, Vector2 dims, RGBA rgba) : rect{ (float)pos.X, (float)pos.Y, dims.X, dims.Y } {
		position = pos;
		colour = rgba;
	}

	Vector2 position;
	RGBA colour{ 0 ,0 ,0 ,0 };
	SDL_FRect rect;

	virtual void Draw(SDL_Renderer* renderer);
	virtual void Update(Game& game, float deltaTime) {};
	bool IsOverlapping(Basic2D& other);
};