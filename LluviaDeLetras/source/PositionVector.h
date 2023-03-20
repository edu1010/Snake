#pragma once
class PositionVector
{
public:
	PositionVector(int x, int y) : x_(x), y_(y) {};
	PositionVector();

	int getX() const;
	void setX(int x);

	int getY() const;
	void setY(int y);

private:
	int x_;
	int y_;
};

