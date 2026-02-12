#include "ScoreUI.h"

ScoreUI::ScoreUI(SDL_Renderer* renderer, Vector2 pos, RGBA rgba) : Basic2D(pos, rgba)
{
	SDL_Color color = { rgba.R, rgba.G, rgba.B, rgba.A };

	font = TTF_OpenFont("fonts/Melon Pop.ttf", 12);

	text = TTF_RenderText_Blended(font, "Hi", 0, color);
	if (text) {
		texture = SDL_CreateTextureFromSurface(renderer, text);
		SDL_DestroySurface(text);
	}

	SDL_GetTextureSize(texture, &rect.w, &rect.h);
	rect.x = pos.X;
	rect.y = pos.Y;
}

void ScoreUI::Draw(SDL_Renderer* renderer) {

	SDL_RenderTexture(renderer, texture, NULL, &rect);

}