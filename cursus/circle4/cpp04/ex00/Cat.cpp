/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:20:44 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 15:01:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout<<"Cat default constructor called"<<std::endl;
}

Cat::Cat(const Cat& original)
{
	std::cout<<"Cat copy constructor called"<<std::endl;
	*this = original;
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat& original)
{
	std::cout<<"Cat copy assignment operator called"<<std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}


void Cat::makeSound(void) const
{
	std::cout<<"Cat make sound: MEOW MEOW"<<std::endl;
}