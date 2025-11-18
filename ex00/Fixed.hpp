#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_intValue;
		static const int	_fractionalBitsNbr = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
