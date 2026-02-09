#include <iostream>
#include <SDL3/SDL.h>
#include "src/Windowing/Window.h"
#include "src/Game.h"

int main() {

	SDL_Init(SDL_INIT_VIDEO);

	std::string name = "hi";
	Game* game = new Game(name, Vector2{ 1080, 720 });

	game->Run();

	delete game;
	SDL_Quit();
	return 0;
}