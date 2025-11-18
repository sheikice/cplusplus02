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


Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "\033[1;32m"
		<< "Copy assignment operator called"
		<< "\033[0m" << std::endl;
	if (this != &other)
		_intValue = other._intValue;
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	if (_intValue > other._intValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
	if (_intValue < other._intValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (_intValue >= other._intValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (_intValue <= other._intValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if (_intValue == other._intValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (_intValue != other._intValue)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(getRawBits() + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(getRawBits() - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(getRawBits() * other.getRawBits() >> _fractionalBitsNbr);
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits((getRawBits() << _fractionalBitsNbr) / other.getRawBits());
	return (res);
}

Fixed Fixed::operator++(void)
{
	Fixed	res(*this);

	this->setRawBits(getRawBits() + 1);
	return (res);
}

Fixed& Fixed::operator++(int)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator--(void)
{
	Fixed	res(*this);

	this->setRawBits(getRawBits() - 1);
	return (res);
}

Fixed& Fixed::operator--(int)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed&			Fixed::min(Fixed& fixA, Fixed& fixB)
{
	return (fixA.getRawBits() < fixB.getRawBits() ? fixA : fixB);
}

const Fixed&	Fixed::min(const Fixed& fixA, const Fixed& fixB)
{
	return (fixA.getRawBits() < fixB.getRawBits() ? fixA : fixB);
}

Fixed&			Fixed::max(Fixed& fixA, Fixed& fixB)
{
	return (fixA.getRawBits() > fixB.getRawBits() ? fixA : fixB);
}

const Fixed&	Fixed::max(const Fixed& fixA, const Fixed& fixB)
{
	return (fixA.getRawBits() > fixB.getRawBits() ? fixA : fixB);
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
