#include "Player.h"
#include "../Game.h"
#include <iostream>
#include "../InputManager.h"

Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D::Basic2D(pos, Vector2{ 15, 75 }, rgba)
{
	playerIndex = index;
}

void Player::Update(Game& game, float deltaTime)
{
	if (IsOverlapping(*game.ball)) {
		game.ball->Flip(*this, playerIndex);
	}

	if (InputManager::GetKeyDown(UpKey)) {
		if ((position.Y + rect.h) <= 0) { position.Y = Bounds.Y - 1; }
		position.Y -= speed * deltaTime;
	}
	if (InputManager::GetKeyDown(DownKey)) {
		if ((position.Y - 1) >= Bounds.Y) { position.Y = 0; }
		position.Y += speed * deltaTime;
	}
}

void Player::AssignZone(ScoreZone* scorezone)
{
	zone = scorezone;
}

void Player::SetBounds(Vector2 bounds)
{
	Bounds = bounds;
}

void Player::SetDownKey(SDL_Keycode key)
{
	DownKey = key;
}

void Player::SetUpKey(SDL_Keycode key)
{
	UpKey = key;
}
