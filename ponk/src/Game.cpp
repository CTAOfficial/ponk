#include "Game.h"
#include <iostream>


Game::Game(std::string& title, Vector2 size) : Window(title, (int)size.X, (int)size.Y)
{
	player1 = new Player(0, Vector2{ 50, 50 }, RGBA{ 255, 255, 255, 255 });
	player2 = new Player(1, Vector2{ 1030, 670 }, RGBA{ 255, 255, 255, 255 });
	Bounds = size;
}

void Game::HandlePoll(SDL_Event event) {
	Window::HandlePoll(event);

	switch (event.type)
	{
		case SDL_EVENT_KEY_DOWN:
			if (event.key.key == SDLK_W) { 
				if ((player1->position.Y + player1->rect.h) <= 0) { player1->position.Y = Bounds.Y - 1; }
				player1->position.Y -= player1->speed;
			}
			if (event.key.key == SDLK_S) {
				if ((player1->position.Y - 1) >= Bounds.Y) { player1->position.Y = 0; }
				player1->position.Y += player1->speed;
			}
			if (event.key.key == SDLK_UP) {
				if ((player2->position.Y + player2->rect.h) <= 0) { player2->position.Y = Bounds.Y - 1; }
				player2->position.Y -= player2->speed;
			}
			if (event.key.key == SDLK_DOWN) {
				if ((player2->position.Y - 1) >= Bounds.Y) { player2->position.Y = 0; }
				player2->position.Y += player2->speed;
			}
			break;
	}
}
void Game::Update() {
	player1->Draw(renderer);
	player2->Draw(renderer);
	player1->Update();
	player2->Update();
}
