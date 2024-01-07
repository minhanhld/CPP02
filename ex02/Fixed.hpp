/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:10:22 by mle-duc           #+#    #+#             */
/*   Updated: 2024/01/07 19:46:51 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP
# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:

	Fixed(void);
	Fixed(const int x);
	Fixed(const float n);
	~Fixed(void);
	Fixed(const Fixed &to_copy);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	float				toFloat(void) const;
	int					toInt(void) const;

	bool	operator>(Fixed fixed) const;
	bool	operator<(Fixed fixed) const;
	bool	operator>=(Fixed fixed) const;
	bool	operator<=(Fixed fixed) const;
	bool	operator==(Fixed fixed) const;
	bool	operator!=(Fixed fixed) const;

	Fixed	operator+(Fixed fixed) const;
	Fixed	operator-(Fixed fixed) const;
	Fixed	operator*(Fixed fixed) const;
	Fixed	operator/(Fixed fixed) const;

	Fixed	&operator=(const Fixed &src);

	Fixed	operator++();
	Fixed	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed	&min(Fixed &x1, Fixed &x2);
	static Fixed	&max(Fixed &x1, Fixed &x2);
	static const Fixed	&max(Fixed const &x1, Fixed const &x2);
	static const Fixed	&min(Fixed const &x1, Fixed const &x2);

	private:

	int					_fp_value;
	static const int	_fractional_bits;
};
std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
