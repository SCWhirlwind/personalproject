#include "Ball.h"

Ball::Ball() : position_(0, 0),
velocity_(0, 0),
rect_ { position_.getX(), position_.getY(), BALL_WIDTH, BALL_HEIGHT}
{
}

Ball::Ball(const int x, const int y) : position_(x, y),
velocity_(0, 0),
rect_{ position_.getX(), position_.getY(), BALL_WIDTH, BALL_HEIGHT }
{
	std::random_device dev;
	std::mt19937 rand_gen(dev());
	std::uniform_int_distribution<> dist_x(0, 1);

	if (dist_x(rand_gen) == 0)
	{
		velocity_.setX(-3);
	}
	else {
		velocity_.setX(3);
	}

	std::uniform_int_distribution<> dist_y(1, 3);

	velocity_.setY(dist_y(rand_gen));

	if (dist_x(rand_gen) == 0)
	{
		velocity_.reverseY();
	}
}

void Ball::update()
{
	position_ += velocity_;

	rect_.x = position_.getX();
	rect_.y = position_.getY();

	if (position_.getY() < 0 || position_.getY() + BALL_HEIGHT > 480)
	{
		velocity_.reverseY();
	}
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect_);
}

bool Ball::collisionCheck(Paddle pad) const
{
	const int leftA = pad.getObject().x;
	const int rightA = pad.getObject().x + pad.getObject().w;

	const int topA = pad.getObject().y;
	const int bottomA = pad.getObject().y + pad.getObject().h;

	const int leftB = rect_.x;
	const int rightB = rect_.x + rect_.w;

	const int topB = rect_.y;
	const int bottomB = rect_.y + rect_.h;

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

	if(velocity_.getX() > 0)
	{
		velocity_.addX(xspeed(rand_gen));

		if (velocity_.getX() <= 0)
		{
			velocity_.setX(2);
		}

		velocity_.reverseX();
	}
	else if(velocity_.getX() < 0)
	{
		velocity_.addX(xspeed(rand_gen));

		if (velocity_.getX() >= 0)
		{
			velocity_.setX(-2);
		}
		velocity_.reverseX();
	}

	velocity_.addY(xspeed(rand_gen));
}

void Ball::reset()
{
	rect_.x = (680 / 2) - 5;
	rect_.y = (480 / 2) + 5;
	position_.setX(rect_.x);
	position_.setY(rect_.y);

	std::random_device dev;
	std::mt19937 rand_gen(dev());
	std::uniform_int_distribution<> dist_x(0, 1);

	if (dist_x(rand_gen) == 0)
	{
		velocity_.setX(-3);
	}
	else 
	{
		velocity_.setX(3);
	}

	std::uniform_int_distribution<> dist_y(1, 3);
	velocity_.setY(dist_y(rand_gen));

	if (dist_x(rand_gen) == 0)
	{
		velocity_.reverseY();
	}
}

int Ball::position()
{
	return position_.getX();
}
