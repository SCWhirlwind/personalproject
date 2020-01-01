#pragma once
#include <SDL.h>
#include <string>

class Window
{
public:
	Window() = default;
	Window(const char* title, int width, int height);
	~Window();

	SDL_Window* getWindow() const;
	void createWindow();

private:
	SDL_Window* window_ = nullptr;
	int width_ = 800;
	int height_ = 640;
	const char* title_ = "Game!";
};

