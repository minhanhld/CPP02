/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 04:27:41 by mle-duc           #+#    #+#             */
/*   Updated: 2024/01/07 19:46:33 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fp_value = x << this->_fractional_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fp_value = roundf(n * (1 << this->_fractional_bits));
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed &Fixed::operator = (const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fp_value / (float)(1 << this->_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fp_value >> this->_fractional_bits);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+(Fixed fixed) const
{
	return (Fixed)(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(Fixed fixed) const
{
	return (Fixed)(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(Fixed fixed) const
{
	return (Fixed)(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(Fixed fixed) const
{
	return (Fixed)(this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fp_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed save = *this;
	this->_fp_value++;
	return (save);
}

Fixed	Fixed::operator--(int)
{
	Fixed save = *this;
	this->_fp_value--;
	return (save);
}

Fixed	&Fixed::min(Fixed &x1, Fixed &x2)
{
	if (x1.toFloat() <= x2.toFloat())
		return (x1);
	return (x2);
}

const Fixed	&Fixed::min(const Fixed &x1, const Fixed &x2)
{
	if (x1.toFloat() <= x2.toFloat())
		return (x1);
	return (x2);
}

Fixed	&Fixed::max(Fixed &x1, Fixed &x2)
{
	if (x1.toFloat() >= x2.toFloat())
		return (x1);
	return (x2);
}

const Fixed	&Fixed::max(const Fixed &x1, const Fixed &x2)
{
	if (x1.toFloat() >= x2.toFloat())
		return (x1);
	return (x2);
}
