#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point	p;
	Point	a;
	Point	b(10,30);
	Point	d(20,0);
	Point	c(d);
	Point	test(10, 15);

	p = test;
	std::cout << "point p(" << p.getX() << ", " << p.getY() << "), "
		<< "point a(" << a.getX() << ", " << a.getY() << "), "
		<< "point b(" << b.getX() << ", " << b.getY() << "), "
		<< "point c(" << c.getX() << ", " << c.getY() << ")" << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "point p(" << p.getX() << ", " << p.getY()
			<< ") is in abc" << std::endl;
	else
		std::cout << "point p(" << p.getX() << ", " << p.getY()
			<< ") is NOT in abc" << std::endl;
	return (0);
}
