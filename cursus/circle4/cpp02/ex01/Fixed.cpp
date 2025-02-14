/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:14:46 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/14 20:21:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int intValue)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->_value = intValue << this->_bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->_value = roundf(floatValue * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = original;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &original)
		this->_value = original.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return(this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout<<"setRawBits member function called"<<std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return(this->_value >> this->_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out<< fixed.toFloat();
	return (out);
}