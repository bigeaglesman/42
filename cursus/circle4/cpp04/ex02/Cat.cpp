/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:20:44 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 22:03:30 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cout<<"Dog brain memory allocation failed"<<std::endl;
		exit(1);
	}
	std::cout<<"Cat default constructor called"<<std::endl;
}

Cat::Cat(const Cat& original)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = original;
}

Cat::~Cat()
{
	delete _brain;
	std::cout<<"Cat destructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat& original)
{
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		this->_type = original._type;
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, original._brain->getIdea(i));
	}
	return (*this);
}


void Cat::makeSound(void) const
{
	std::cout<<"Cat make sound: MEOW MEOW"<<std::endl;
}

std::string Cat::getIdea(size_t n) const
{
	return (this->_brain->getIdea(n));
}

void Cat::setIdea(const size_t n, std::string idea)
{
	this->_brain->setIdea(n, idea);
}