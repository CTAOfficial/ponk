#pragma once

#include "Windowing/Window.h"
#include "Entities/Player.h"
#include "Entities/Ball.h"
#include "Logic/ScoreZone.h"

class Game : public Window {
private:
	ScoreZone* score1 = nullptr;
	ScoreZone* score2 = nullptr;
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	Ball* ball = nullptr;
	Vector2 Bounds;
	Vector2 PlayerBounds;

public:
	Game(std::string& title, Vector2 size);
	void HandlePoll(SDL_Event event) override;
	void Update() override;
};