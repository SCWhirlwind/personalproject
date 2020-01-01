#pragma once
#include "Object.h"
#include "Vector2D.h"

class Paddle : public Object
{
public:

	Paddle();
	Paddle(int x, int y);

	void up();
	void down();
	void stop();
	SDL_Rect getObject() const;
	void update() override;
	void draw(SDL_Renderer* renderer) override;

	const int PADDLE_WIDTH = 10;
	const int PADDLE_HEIGHT = 75;

private:

	Vector2D position_;
	Vector2D velocity_;

	SDL_Rect rect_;
};
