#pragma once

#include "Windowing/Window.h"
#include "Entities/Ball.h"
#include "Logic/ScoreManager.h"
#include "Logic/ScoreZone.h"
#include "UI/TextUI.h"
#include <string>
#include "Vector2.h"

class Player;

class Game : public Window {
private:
	
	Vector2 Bounds;
	Vector2 PlayerBounds;
	ScoreManager* scoreManager = nullptr;
	TextUI* ui = nullptr;

public:
	Game(std::string& title, Vector2 size);

	Vector2 screenCenter;
	ScoreZone* score1 = nullptr;
	ScoreZone* score2 = nullptr;
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	Ball* ball = nullptr;

	void Update() override;
};