#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_intValue;
		static const int	_fractionalBitsNbr = 8;

	public:
		Fixed(void);
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		~Fixed(void);

		int				getRawBits(void) const;
		void			setRawBits(const int);
		float			toFloat(void) const;
		int				toInt(void) const;

		Fixed&			operator=(const Fixed&);
		bool			operator>(const Fixed&) const;
		bool			operator<(const Fixed&) const;
		bool			operator>=(const Fixed&) const;
		bool			operator<=(const Fixed&) const;
		bool			operator==(const Fixed&) const;
		bool			operator!=(const Fixed&) const;
		Fixed				operator+(const Fixed&) const;
		Fixed				operator-(const Fixed&) const;
		Fixed				operator*(const Fixed&) const;
		Fixed				operator/(const Fixed&) const;
		Fixed				operator++(void);
		Fixed&				operator++(int);
		Fixed				operator--(void);
		Fixed&				operator--(int);

		static Fixed&			min(Fixed&, Fixed&);
		static const Fixed&		min(const Fixed&, const Fixed&);
		static Fixed&			max(Fixed&, Fixed&);
		static const Fixed&		max(const Fixed&, const Fixed&);
};
 
std::ostream&	operator<<(std::ostream&, Fixed&);
std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
