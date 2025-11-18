#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangleArea;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	triangleArea = calculateArea(a, b, c);
	area1 = calculateArea(point, a, b);
	area2 = calculateArea(point, b, c);
	area3 = calculateArea(point, a, c);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	if ((area1 + area2 + area3) == triangleArea)
		return (true);
	else
		return (false);
}

Fixed calculateArea(Point const a, Point const b, Point const c)
{
	Fixed	area;

	area = (a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY())) / 2;

	if (area < 0)
		return (area * -1);
	else
		return (area);
}
