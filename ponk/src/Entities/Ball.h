#pragma once
#include "Basic2D.h"
#include "../RGBA.h"

class Ball : public Basic2D {
public:
	Ball(RGBA rgba);

	float speed = 3.5f;
};