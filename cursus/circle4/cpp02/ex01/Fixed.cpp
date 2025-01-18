/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:14:46 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/19 06:03:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	_value = 0;
}

Fixed::Fixed(const int intValue)
{
	std::cout<<"Int constructor called"<<std::endl;
	_value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout<<"Float constructor called"<<std::endl;
	_value = roundf(floatValue * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout<<"Copy constructor called"<<std::endl;
	_value = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this == &original)
		return (*this);
	_value = original.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return(_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout<<"setRawBits member function called"<<std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return(static_cast<float>(_value) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return(_value >> _bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out<< fixed.toFloat();
	return (out);
}