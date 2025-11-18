#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point&);
		~Point(void);
		Point	operator=(const Point&);
		bool	operator==(const Point& other) const;
		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed	calculateArea(Point const a, Point const b, Point const c);

#endif
