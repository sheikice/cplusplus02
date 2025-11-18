#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _intValue(0)
{
	std::cout << "\033[1;32m"
		<< "Default constructor called"
		<< "\033[0m" << std::endl;
}

Fixed::Fixed(const int value)
{
	setRawBits(value << _fractionalBitsNbr);
	std::cout << "\033[1;32m"
		<< "Int constructor called"
		<< "\033[0m" << std::endl;
}

Fixed::Fixed(const float value)
{
	setRawBits(roundf(value * (1 << _fractionalBitsNbr)));
	std::cout << "\033[1;32m"
		<< "Float constructor called"
		<< "\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed& other): _intValue(other._intValue)
{
	std::cout << "\033[1;32m"
		<< "Copy constructor called"
		<< "\033[0m" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "\033[1;32m"
		<< "Copy assignment operator called"
		<< "\033[0m" << std::endl;
	if (this != &other)
		_intValue = other._intValue;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

std::ostream&	operator<<(std::ostream& os, Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed(void)
{
	std::cout << "\033[1;31m"
		<< "Destructor called"
		<< "\033[0m" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (_intValue);
}

void	Fixed::setRawBits(int const raw)
{
	_intValue = raw;
}

int		Fixed::toInt() const
{
	return (_intValue >> _fractionalBitsNbr);
}

float	Fixed::toFloat() const
{
	return ((float)_intValue / (1 << _fractionalBitsNbr));
}
