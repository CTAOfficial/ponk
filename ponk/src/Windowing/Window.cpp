#include <iostream>
#include <string>
#include "Window.h"

Window::Window(std::string& title, int width, int height)
{
	Width = width;
	Height = height;

	SDL_CreateWindowAndRenderer(
		title.c_str(),
		Width,
		Height,
		NULL,
		&window,
		&renderer
	);

	if (window == nullptr) {
		std::cout << "Failed to initialize SDL Window\n";
	}
	if (renderer == nullptr) {
		std::cout << "Failed to initialize SDL Renderer\n";
	}

	Title = title;
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Window::Run()
{
	IsRunning = true;
	while (IsRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			HandlePoll(event);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		Update();
		SDL_RenderPresent(renderer);
	}
}

void Window::HandlePoll(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_EVENT_QUIT:
			Close();
			break;
		case SDL_EVENT_KEY_DOWN:
			if (event.key.key == SDLK_ESCAPE) { Close(); }
			break;
			
	}
}

void Window::Update()
{

}

void Window::Close()
{
	IsRunning = false;
	OnClose();
	//delete this;
}

void Window::OnClose()
{
}

Window* Window::Create(std::string title, int width, int height)
{
	Window* window = new Window(title, width, height);
	return window;
}
