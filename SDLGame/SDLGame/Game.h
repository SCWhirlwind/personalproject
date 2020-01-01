#pragma once
#include "SDL.h"
#include  "Object.h"
#include "Ball.h"
#include "Paddle.h"

enum obj { left = 0, right, ball };
const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

class Game
{
public:

	Game();
	~Game() = default;

	void loop();
	void update();
	void render();
	void handleEvents();
	void clean() const;

	bool isRunning() const { return is_running_; }

private:

	bool is_running_ = false;

	SDL_Window* window_ = nullptr;
	SDL_Renderer* renderer_ = nullptr;
	SDL_Event event_;
	Object* container_[3];
	Paddle left_paddle;
	Paddle right_paddle;
	Ball ball;
};
