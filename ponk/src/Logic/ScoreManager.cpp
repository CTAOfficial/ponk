#include "ScoreManager.h"
#include "ScoreZone.h"
#include "../UI/TextUI.h"
#include <string>

ScoreManager* ScoreManager::Instance;


ScoreManager::ScoreManager(SDL_Renderer* renderer, Vector2 pos, RGBA rgba)
{
	if (Instance != nullptr) {
		delete this;
	}

	Instance = this;

	text = new TextUI{ "build/fonts/Melon Pop.ttf", renderer, pos, rgba };
}

void ScoreManager::AddZone(ScoreZone& zone)
{
	Instance->zones.push_back(&zone);
}

void ScoreManager::SetTextPosition(Vector2 pos) {
	Instance->text->position = pos;
}
void ScoreManager::Update()
{
	std::string input = "";
	for (int i = 0; i < Instance->zones.size(); i++) {
		input += std::to_string(Instance->zones.at(i)->GetScore());

		if (i != Instance->zones.size() - 1) {
			input += " : ";
		}
	}

	Instance->text->SetText(input);
}
void ScoreManager::Render(SDL_Renderer* renderer) {
	Instance->text->Draw(renderer);
}
