/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:14:07 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/26 23:20:46 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout<<"Cure default constuctor called"<<std::endl;
}

Cure::Cure(const Cure &original) : AMateria(original)
{
	std::cout<<"Cure copy constructor called"<<std::endl;
}

Cure::~Cure()
{
	std::cout<<"Cure destructor called"<<std::endl;
}

Cure& Cure::operator=(const Cure &original)
{
	std::cout<<"Cure copy assigment called"<<std::endl;
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}