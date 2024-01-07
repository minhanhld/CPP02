/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:10:22 by mle-duc           #+#    #+#             */
/*   Updated: 2024/01/07 17:45:14 by mle-duc          ###   ########.fr       */
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
	Fixed &operator = (const Fixed &src);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	private:

	int					_fp_value;
	static const int	_fractional_bits;
};
std::ostream	&operator<<(std::ostream &os, Fixed const &fixed);

#endif
