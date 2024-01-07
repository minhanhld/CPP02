/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:10:22 by mle-duc           #+#    #+#             */
/*   Updated: 2024/01/07 04:29:21 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP
# include <iostream>
# include <string>

class Fixed
{
	public:

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &to_copy);
	Fixed &operator = (const Fixed &src);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	private:

	int					_fp_value;
	static const int	_fractional_bits;
};

#endif
