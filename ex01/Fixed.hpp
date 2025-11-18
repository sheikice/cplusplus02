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
		Fixed&			operator=(const Fixed&);
		int				getRawBits(void) const;
		void			setRawBits(const int);
		float			toFloat(void) const;
		int				toInt(void) const;
};
 
std::ostream&	operator<<(std::ostream&, Fixed&);
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
