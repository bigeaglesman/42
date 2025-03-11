/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:42:33 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/22 19:24:25 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout<<"AMateria default constructor called"<<std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout<<"AMateria type paramater constructor called"<<std::endl;
}

AMateria::AMateria(const AMateria& original)
{
	std::cout<<"AMateria copy constructor called"<<std::endl;
	*this = original;
}

AMateria& AMateria::operator=(const AMateria &original)
{
	std::cout<<"AMateria copy assignment operator called"<<std::endl;
	if (this != &original)
		this->_type = original.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout<<"AMateria destructor called"<<std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter & target)
{
	(void)target;
}