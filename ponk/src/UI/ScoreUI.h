#pragma once

#include <SDL3_ttf/SDL_ttf.h>
#include "../Entities/Basic2D.h"


class ScoreUI : public Basic2D {
public:
	ScoreUI(SDL_Renderer* renderer, Vector2 pos, RGBA rgba);

	SDL_Texture* texture = nullptr;
	TTF_Font* font = nullptr;
	SDL_Color color = { 255, 255, 255, SDL_ALPHA_OPAQUE };
	SDL_Surface* text = nullptr;

	void Draw(SDL_Renderer* renderer) override;
};