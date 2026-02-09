#pragma once
#include <SDL3/SDL_events.h>
#include <list>
#include <iostream>
#include <vector>

static class InputManager {
private:
	static std::list<SDL_Keycode> downKeys;
	static std::list<SDL_Keycode> upKeys;
	static std::vector<SDL_Keycode> pressedKeys;

	static void HandleKeysDown() {
		
	}
	static void HandleKeysUp() {

	}

public:
	/*static void Update() {
		pressedKeys.clear();

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			default:
				std::cout << "Event Not Handled";
				break;
			case SDL_EVENT_KEY_UP:
				HandleKeysUp(event);
				break;
			case SDL_EVENT_KEY_DOWN:
				HandleKeysDown(event);				
				break;

			}
		}
	}
	static bool GetKeyDown(SDL_Keycode key) {
		if (pressedKeys.contains)

		return false;
	}*/
};