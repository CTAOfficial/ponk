#include "ScoreZone.h"
#include "../UI/TextUI.h"
#include "ScoreManager.h"

ScoreZone::ScoreZone(Vector2 pos, Vector2 dims, RGBA rgba) : Basic2D(pos, dims, rgba)
{
	ScoreManager::AddZone(*this);
}

void ScoreZone::Score()
{
	score++;
	Notify(ScoreManager::GetInstance());
}

void ScoreZone::SetUI(TextUI* ui)
{
	textUI = ui;
}

void ScoreZone::Notify(ScoreManager& manager)
{
	manager.Update();
}
