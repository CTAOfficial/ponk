#pragma once

#include "../UI/TextUI.h"
#include "../Vector2.h"
#include "../RGBA.h"
#include <vector>
#include <SDL3/SDL_render.h>

class ScoreZone;

class ScoreManager {
private:
	static ScoreManager* Instance;
	std::vector<ScoreZone*> zones;
	TextUI* text;

public:
	ScoreManager(SDL_Renderer* renderer, Vector2 pos, RGBA rgba);

	static void AddZone(ScoreZone& zone);
	static void SetTextPosition(Vector2 pos);
	static void Update();
	static void Render(SDL_Renderer* renderer);
	static ScoreManager& GetInstance() {
		return *Instance;
	}

};