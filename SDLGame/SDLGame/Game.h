#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:

	Game() = default;
	~Game() = default;

	Game(const Game& copy) noexcept(false);
	Game& operator=(const Game& rhs) noexcept(false);
	Game(Game&& copy) noexcept;
	Game& operator=(Game&& rhs) noexcept;

	void init(const char* title, int width, int height, bool fullscreen);

	void handle_events();
	void update();
	bool running() const { return is_running_; }
	void render() const;
	void clean() const;

private:

	bool is_running_ = false;
	int cnt_ = 0;
	SDL_Window* window_ = nullptr;
	SDL_Renderer* renderer_ = nullptr;
};