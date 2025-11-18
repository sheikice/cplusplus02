#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& other): _x(other._x), _y(other._y) {}

Point::~Point(void) {}

Point	Point::operator=(const Point& other)
{
	Point	point(other);

	return (point);
}

bool	Point::operator==(const Point& other) const
{
	if (_x == other._x && _y == other._y)
		return (true);
	else
		return (false);
}

const Fixed&	Point::getX(void) const
{
	return (_x);
}

const Fixed&	Point::getY(void) const
{
	return (_y);
}
