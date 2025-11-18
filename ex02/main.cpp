#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b( 2 );
	Fixed const b2( 2 );
	Fixed c;
	Fixed d;
	Fixed e;
	Fixed f;
	Fixed g;

	a = Fixed( 42.42f );
	Fixed const a2(a);
	// a = Fixed( 1234.4321f );

	// c = a + b;
	// d = a - b;
	// e = a * b;
	f = a / b;
	g = f * b;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	// std::cout << "c = a + b is " << c << std::endl;
	// std::cout << "d = a - b is " << d << std::endl;
	// std::cout << "e = a * b is " << e << std::endl;
	std::cout << "f = a / b is " << f << std::endl;
	std::cout << "g = f * b is " << g << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "max(a,b) = " << Fixed::max(a,b) << std::endl;
	std::cout << "min(a,b) = " << Fixed::min(a,b) << std::endl;
	std::cout << "max(a2,b) = " << Fixed::max(a2,b) << std::endl;
	std::cout << "min(a2,b) = " << Fixed::min(a2,b) << std::endl;
	std::cout << "min(a2,b2) = " << Fixed::min(a2,b2) << std::endl;
	std::cout << "max(a2,b2) = " << Fixed::max(a2,b2) << std::endl;

	return (0);
}
