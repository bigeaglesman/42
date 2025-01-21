/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:04:29 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/22 02:33:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout<<"Dog default constructor called"<<std::endl;
}

Dog::Dog(const Dog& original)
{
	std::cout<<"Dog copy constructor called"<<std::endl;
	*this = original;
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
}


Dog& Dog::operator=(const Dog& original)
{
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

void Dog::makeSound(void)
{
	std::cout<<"Dog make sound: BARK BARK"<<std::endl;
}