/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:14:07 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/22 18:43:56 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout<<"Cure default constuctor called"<<std::endl;
}

Cure::~Cure()
{
	std::cout<<"Cure destructor called"<<std::endl;
}

Cure* Cure::clone() const
{
	if (DEBUG)
		std::cout<<"Cure clone called"<<std::endl;
	return (new Cure());
}

Cure& Cure::operator=(const Cure &original)
{
	std::cout<<"Cure copy assignment oprator called"<<std::endl;
	this->_type = original.getType();
	return (*this);
}

Cure::Cure(Cure const &original)
{
	std::cout<<"Cure copy constructor called"<<std::endl;
	*this = original;
}

void Cure::use(ICharacter &target)
{
	if (DEBUG)
		std::cout<<"Cure use called"<<std::endl;
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}