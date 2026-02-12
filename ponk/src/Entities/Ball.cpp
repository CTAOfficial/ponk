#include "Ball.h"
#include "../RGBA.h"
#include "../Game.h"
#include <iostream>


Ball::Ball(Vector2 pos, RGBA rgba) : Basic2D::Basic2D(pos, Vector2{ 10, 10 }, rgba)
{
	velocity = { 1, 1};
}

void Ball::Update(Game& game, float deltaTime)
{

	float movementX = (velocity.X * speed) * deltaTime;
	float movementY = (velocity.Y * speed) * deltaTime;

	position.X += movementX;
	position.Y += movementY;

	CheckBounds();

	if (IsOverlapping(*game.score1)) 
	{
		game.score1->score++;
		std::cout << "Score 1: " << game.score1->score << "\n";
		Reset(game, 0);
	}
	else if (IsOverlapping(*game.score2)) {
		game.score2->score++;
		std::cout << "Score 2: " << game.score2->score << "\n";
		Reset(game, 0);
	}
}

void Ball::Flip(Basic2D& contact, int playerIndex)
{
	if (LastContact != nullptr && IsOverlapping(*LastContact)) {
		return;
	}
	LastContact = &contact;

	std::cout << "Ball Flipped!\n";
	player = playerIndex;
	std::cout << "Old Velocity: (" << velocity.X << ", " << velocity.Y << ")\n";
	velocity = Vector2{ -velocity.X, -velocity.Y };
	std::cout << "New Velocity: (" << velocity.X << ", " << velocity.Y << ")\n";
}

void Ball::Reset(Game& game, int playerIndex)
{
	position = game.screenCenter;
	player = playerIndex;
	LastContact = nullptr;
}

void Ball::CheckBounds()
{
	if (position.X < 0 || position.X > bounds.X) {
		velocity.X = -velocity.X;
	}
	if (position.Y < 0 || position.Y > bounds.Y) {
		velocity.Y = -velocity.Y;
	}
}
void Ball::SetBounds(Vector2 bounds)
{
	this->bounds = bounds;
}
