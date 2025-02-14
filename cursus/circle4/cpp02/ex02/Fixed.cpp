/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:24:44 by ycho              #+#    #+#             */
/*   Updated: 2025/02/14 21:17:13 by ycho2            ###   ########.fr       */
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

// 전위 증감 연산자
Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

// 후위 증감 연산자
const Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

const Fixed Fixed::operator--(int)
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
