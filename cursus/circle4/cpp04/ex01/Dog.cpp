/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:04:29 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/20 09:02:08 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout<<"Dog default constructor called"<<std::endl;
}

Dog::Dog(const Dog& original)
{
	this->_brain = new Brain();
	*this = original;
	std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout<<"Dog destructor called"<<std::endl;
}


Dog& Dog::operator=(const Dog& original)
{
	std::cout<<"Dog copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		this->_type = original._type;
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, original._brain->getIdea(i));
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout<<"Dog make sound: BARK BARK"<<std::endl;
}

std::string Dog::getIdea(size_t n) const
{
	return (this->_brain->getIdea(n));
}

void Dog::setIdea(const size_t n, std::string idea)
{
	this->_brain->setIdea(n, idea);
}