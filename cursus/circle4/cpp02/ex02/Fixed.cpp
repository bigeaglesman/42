/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho <ycho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:24:44 by ycho              #+#    #+#             */
/*   Updated: 2025/01/20 11:41:58 by ycho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int intValue)
{
	// std::cout<<"Int constructor called"<<std::endl;
	_value = intValue *(1 << _bits);
}

Fixed::Fixed(const float floatValue)
{
	// std::cout<<"Float constructor called"<<std::endl;
	_value = roundf(floatValue * (1 << _bits));
}

Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &original)
{
	// std::cout<<"Copy constructor called"<<std::endl;
	_value = original.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& original)
{
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

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const 
{
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed tmp(this->toFloat() + other.toFloat());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed tmp(this->toFloat() - other.toFloat());
	return (tmp);
}
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed tmp(this->toFloat() * other.toFloat());
	return (tmp);
}
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed tmp(this->toFloat() / other.toFloat());
	return (tmp);
}

Fixed Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out<<fixed.toFloat();
	return (out);
}