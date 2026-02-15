#include "Ball.h"
#include "../RGBA.h"
#include "../Game.h"
#include <iostream>


Ball::Ball(Vector2 pos, RGBA rgba) : Basic2D::Basic2D(pos, Vector2{ 10, 10 }, rgba)
{
	velocity = { 1, 1};
	originalSpeed = speed;
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
		game.score1->Score();
		std::cout << "Score 1: " << game.score1->GetScore() << "\n";
		Reset(game);
	}
	else if (IsOverlapping(*game.score2)) {
		game.score2->Score();
		std::cout << "Score 2: " << game.score2->GetScore() << "\n";
		Reset(game);
	}
}

void Ball::Flip(Basic2D& contact)
{
	if (LastContact != nullptr && IsOverlapping(*LastContact)) {
		return;
	}
	LastContact = &contact;

	velocity = Vector2{ -velocity.X, -velocity.Y };
	speed += 25;
}

void Ball::Reset(Game& game)
{
	speed = originalSpeed;
	position = game.screenCenter;
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
