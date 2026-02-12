#include "Game.h"
#include <iostream>
#include "InputManager.h"


Game::Game(std::string& title, Vector2 size) : Window(title, (int)size.X, (int)size.Y)
{
	screenCenter = Vector2{ size.X * 0.5f, size.Y * 0.5f };
	Bounds = size;

	player1 = new Player(0, Vector2{ 50, 50 }, RGBA{ 255, 255, 255, 255 });
	player1->SetUpKey(SDLK_W);
	player1->SetDownKey(SDLK_S);
	player1->SetBounds(Bounds);

	player2 = new Player(1, Vector2{ 1030, 670 }, RGBA{ 255, 255, 255, 255 });
	player2->SetUpKey(SDLK_UP);
	player2->SetDownKey(SDLK_DOWN);
	player2->SetBounds(Bounds);

	score1 = new ScoreZone(Vector2{ 0, 0 }, Vector2{ 10, size.Y }, RGBA{ 255, 0, 0, 0 });
	score2 = new ScoreZone(Vector2{ Bounds.X - 10, 0 }, Vector2{ 10, size.Y }, RGBA{ 0, 255, 0, 0 });
	
	player1->AssignZone(score1);
	player2->AssignZone(score2);

	ball = new Ball(screenCenter, RGBA{ 0, 213, 145, 0 });
	ball->SetBounds(Bounds);

}

/*void Game::HandlePoll(SDL_Event event) {
	Window::HandlePoll(event);

	switch (event.type)
	{
		case SDL_EVENT_KEY_DOWN:
			if (event.key.key == SDLK_ESCAPE) { Close(); break; }

			if (event.key.key == SDLK_W) { 
				if ((player1->position.Y + player1->rect.h) <= 0) { player1->position.Y = Bounds.Y - 1; }
				player1->position.Y -= player1->speed * deltaTime;
			}
			if (event.key.key == SDLK_S) {
				if ((player1->position.Y - 1) >= Bounds.Y) { player1->position.Y = 0; }
				player1->position.Y += player1->speed * deltaTime;
			}
			if (event.key.key == SDLK_UP) {
				if ((player2->position.Y + player2->rect.h) <= 0) { player2->position.Y = Bounds.Y - 1; }
				player2->position.Y -= player2->speed * deltaTime;
			}
			if (event.key.key == SDLK_DOWN) {
				if ((player2->position.Y - 1) >= Bounds.Y) { player2->position.Y = 0; }
				player2->position.Y += player2->speed * deltaTime;
			}
			break;
	}
}*/
void Game::Update() {

	if (InputManager::GetKey(SDLK_ESCAPE)) { Close(); }

	score1->Draw(renderer);
	score2->Draw(renderer);
	ball->Draw(renderer);
	player1->Draw(renderer);
	player2->Draw(renderer);
	

	ball->Update(*this, deltaTime);
	player1->Update(*this, deltaTime);
	player2->Update(*this, deltaTime);
}
