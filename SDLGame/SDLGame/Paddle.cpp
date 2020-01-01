#include "Paddle.h"

Paddle::Paddle() : position_(0, 0), 
velocity_(0, 0), 
rect_{ position_.getX(), position_.getY(), PADDLE_WIDTH, PADDLE_HEIGHT }
{
}

Paddle::Paddle(const int x, const int y) : position_(x, y), 
velocity_(0, 0),
rect_{ position_.getX(), position_.getY(), PADDLE_WIDTH, PADDLE_HEIGHT }
{
}

void Paddle::up()
{
	velocity_.setY(-5);
}

void Paddle::down()
{
	velocity_.setY(5);
}

void Paddle::stop()
{
	velocity_.reset();
}

SDL_Rect Paddle::getObject() const
{
	return rect_;
}

void Paddle::update()
{
	position_ += velocity_;

	rect_.x = position_.getX();
	rect_.y = position_.getY();

	if (position_.getY() < 0 || position_.getY() + PADDLE_HEIGHT > 480)
	{
		position_.addY(-velocity_.getY());
		rect_.y = position_.getY();
	}
}

void Paddle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect_);
}

