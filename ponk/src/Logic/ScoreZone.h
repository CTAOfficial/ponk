#pragma once
#include "../Entities/Basic2D.h"
#include "../RGBA.h"
#include "../Vector2.h"

class ScoreZone : public Basic2D {
public:
	ScoreZone(Vector2 pos, Vector2 dims, RGBA rgba);

	int score = 0;
};