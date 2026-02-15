#pragma once
#include "../Entities/Basic2D.h"
#include "../RGBA.h"
#include "../Vector2.h"
#include "ScoreManager.h"

class TextUI;

class ScoreZone : public Basic2D {
private:
	int score = 0;
	TextUI* textUI = 0;

public:
	ScoreZone(Vector2 pos, Vector2 dims, RGBA rgba);

	void Score();
	int GetScore() const {
		return score;
	}
	void SetUI(TextUI* ui);
	void Notify(ScoreManager& manager);
};