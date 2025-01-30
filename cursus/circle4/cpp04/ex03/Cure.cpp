/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:14:07 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 21:46:32 by ycho2            ###   ########.fr       */
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

void Cure::use(ICharacter &target)
{
	if (DEBUG)
		std::cout<<"Cure use called"<<std::endl;
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}