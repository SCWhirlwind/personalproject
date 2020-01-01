#include "Ball.h"

Ball::Ball() : position_(0, 0), velocity_(0, 0),
{
	ypos_ = 0;
	xpos_ = 0;

	yvel_ = 0;
	xvel_ = 0;

	collider_.x = 0;
	collider_.y = 0;

	collider_.w = BALL_WIDTH;
	collider_.h = BALL_HEIGHT;
}

Ball::Ball(const int x, const int y)
{
	collider_.x = x;
	collider_.y = y;

	collider_.w = BALL_WIDTH;
	collider_.h = BALL_HEIGHT;

	xpos_ = collider_.x;
	ypos_ = collider_.y;

	std::random_device dev;
	std::mt19937 rand_gen(dev());
	std::uniform_int_distribution<> dist_x(0, 1);

	if (dist_x(rand_gen) == 0)
	{
		xvel_ = -3;
	}
	else {
		xvel_ = 3;
	}

	std::uniform_int_distribution<> dist_y(1, 3);
	yvel_ = dist_y(rand_gen);

	if (dist_x(rand_gen) == 0)
	{
		yvel_ = -yvel_;
	}
}

void Ball::update()
{
	xpos_ += xvel_;
	ypos_ += yvel_;

	collider_.x = xpos_;
	collider_.y = ypos_;

	if (ypos_ < 0 || ypos_ + BALL_HEIGHT > 480)
	{
		yvel_ = -yvel_;
	}
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &collider_);
}

bool Ball::collisionCheck(Paddle pad) const
{
	const int leftA = pad.getObject().x;
	const int rightA = pad.getObject().x + pad.getObject().w;

	const int topA = pad.getObject().y;
	const int bottomA = pad.getObject().y + pad.getObject().h;

	const int leftB = collider_.x;
	const int rightB = collider_.x + collider_.w;

	const int topB = collider_.y;
	const int bottomB = collider_.y + collider_.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}

void Ball::reverse()
{
	std::random_device dev;
	std::mt19937 rand_gen(dev());
	const std::uniform_int_distribution<> xspeed(-3, 3);

	if(xvel_ > 0)
	{
		xvel_ += xspeed(rand_gen);
		if (xvel_ <= 0)
		{
			xvel_ = 2;
		}
		xvel_ = -xvel_;
	}
	else if(xvel_ < 0)
	{
		xvel_ += xspeed(rand_gen);
		if (xvel_ >= 0)
		{
			xvel_ = -2;
		}
		xvel_ = -xvel_;
	}

	yvel_ += xspeed(rand_gen);
}

void Ball::reset()
{
	collider_.x = (680 / 2) + 5;
	collider_.y = (680 / 2) + 5;

	xpos_ = collider_.x;
	ypos_ = collider_.y;

	std::random_device dev;
	std::mt19937 rand_gen(dev());
	std::uniform_int_distribution<> dist_x(0, 1);

	if (dist_x(rand_gen) == 0)
	{
		xvel_ = -3;
	}
	else {
		xvel_ = 3;
	}

	std::uniform_int_distribution<> dist_y(1, 3);
	yvel_ = dist_y(rand_gen);

	if (dist_x(rand_gen) == 0)
	{
		yvel_ = -yvel_;
	}
}

int Ball::position() const
{
	return xpos_;
}
