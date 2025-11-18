#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _intValue(0) {
	std::cout << "\033[1;32m"
		<< "Default constructor called"
		<< "\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _intValue(other._intValue)
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

Fixed::~Fixed(void)
{
	std::cout << "\033[1;31m"
		<< "Destructor called"
		<< "\033[0m" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "\033[1;33m"
		<< "getRawBits member function called"
		<< "\033[0m" << std::endl;
	return (_intValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[1;33m"
		<< "setRawBits member function called"
		<< "\033[0m" << std::endl;
	_intValue = raw << _fractionalBitsNbr;
}
