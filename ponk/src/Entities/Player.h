#pragma once
#include "../RGBA.h"
#include "Basic2D.h"
#include <SDL3/SDL_render.h>
#include <queue>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Player : public Basic2D {

public:
	Player(int index, Vector2 pos, RGBA rgba);

	int playerIndex = 0;
	float speed = 5;

	void Draw(SDL_Renderer* renderer);
	void Update();
};