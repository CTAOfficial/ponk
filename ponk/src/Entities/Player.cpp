#include "Player.h"
#include <iostream>

Player::Player(int index, Vector2 pos, RGBA rgba) : Basic2D::Basic2D(pos, rgba)
{
	playerIndex = index;
}

void Player::Draw(SDL_Renderer* renderer)
{
	rect = { position.X, position.Y, 15, 75 };
	SDL_SetRenderDrawColor(renderer, colour.R, colour.G, colour.B, colour.A);
	SDL_RenderFillRect(renderer, &rect);
}

void Player::Update()
{
	
}