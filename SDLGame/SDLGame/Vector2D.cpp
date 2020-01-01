#include "Vector2D.h"

Vector2D::Vector2D(const int x, const int y)
{
	x_ = x;
	y_ = y;
}

Vector2D Vector2D::operator+(Vector2D const& rhs) const
{
	return { x_ + rhs.x_, y_ + rhs.y_ };
}

Vector2D& Vector2D::operator+=(Vector2D const& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;

	return *this;
}

int& Vector2D::getX()
{
	return x_;
}

int& Vector2D::getY()
{
	return y_;
}

void Vector2D::setX(const int x)
{
	x_ = x;
}

void Vector2D::setY(const int y)
{
	y_ = y;
}

void Vector2D::addX(const int x)
{
	x_ += x;
}

void Vector2D::addY(const int y)
{
	y_ += y;
}

void Vector2D::reverseX()
{
	x_ = -x_;
}

void Vector2D::reverseY()
{
	y_ = -y_;
}

void Vector2D::reset()
{
	x_ = 0;
	y_ = 0;
}
