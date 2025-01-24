/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:04:53 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 23:00:14 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(const Animal& original)
{
	std::cout<<"Animal copy constructor called"<<std::endl;
	*this = original;
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called"<<std::endl;
}

Animal& Animal::operator=(const Animal& original)
{
	std::cout<<"Animal copy assignment operator called"<<std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	// std::cout<<"Animal make sound: HI HI"<<std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}