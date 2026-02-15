#include <iostream>
#include <SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include "src/Windowing/Window.h"
#include "src/Game.h"
#include <string>

bool Initialize() {

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL Failed to initialize.\n";
		return false;
	}
	if (!TTF_Init()) {
		std::cout << "SDL_TTF Failed to initialize.\n";
		return false;
	}

	return true;
}

int main() {

	if (!Initialize()) {
		return -1;
	}


	std::string name = "ponk";
	Game* game = new Game(name, Vector2{ 1080, 720 });

	game->Run();

	delete game;
	TTF_Quit();
	SDL_Quit();
	return 0;
}

