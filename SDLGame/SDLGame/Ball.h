#pragma once
#include "Object.h"
#include "Paddle.h"
#include <random>

class Ball : public Object
{
public:

	Ball();
	Ball(int x, int y);
	void update() override;
	void draw(SDL_Renderer* renderer) override;

	bool collisionCheck(Paddle pad) const;
	void reverse();
	void reset();
	int position();

	const int BALL_WIDTH = 10;
	const int BALL_HEIGHT = 10;
private:

	Vector2D position_;
	Vector2D velocity_;

	SDL_Rect rect_;
};
