#pragma once
#include "Basic2D.h"
#include "../RGBA.h"

class Ball : public Basic2D {
private:
	Vector2 velocity;
	Vector2 bounds;
	int player = 0;
	bool Flipping = false;
	Basic2D* LastContact = nullptr;

	void CheckBounds();

public:
	Ball(Vector2 pos, RGBA rgba);

	float speed = 200.0f;

	void Update(Game& game, float deltaTime) override;

	void Flip(Basic2D& contact, int playerIndex);
	void Reset(Game& game, int playerIndex);
	void SetBounds(Vector2 bounds);
};