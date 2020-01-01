#pragma once
class Vector2D
{
public:

	Vector2D() = default;
	Vector2D(int x, int y);

	Vector2D operator+(Vector2D const& rhs) const;
	Vector2D& operator+=(Vector2D const& rhs);

	int& getX();
	int& getY();

	void setX(int x);
	void setY(int y);

	void addX(int x);
	void addY(int y);

	void reverseX();
	void reverseY();

	void reset();

private:
	int x_ = 0;
	int y_ = 0;
};

