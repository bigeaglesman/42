/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:00:53 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 23:00:16 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("WrongAnimal")
{
	std::cout<<"WrongAnimal default constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	std::cout<<"WrongAnimal copy constructor called"<<std::endl;
	*this = original;
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destructor called"<<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	std::cout<<"WrongAnimal copy assignment operator called"<<std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	// std::cout<<"WrongAnimal make sound: IH IH"<<std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}