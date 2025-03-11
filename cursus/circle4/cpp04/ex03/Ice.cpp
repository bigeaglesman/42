/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:12:53 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/22 19:06:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// 명시적으로 부모의 매개변수 생성자 호출
Ice::Ice() : AMateria("ice")
{
	std::cout<<"Ice default constuctor called"<<std::endl;
}

Ice::~Ice()
{
	std::cout<<"Ice destructor called"<<std::endl;
}

Ice* Ice::clone() const
{
	if (DEBUG)
		std::cout<<"Ice clone called"<<std::endl;
	return (new Ice());
}

Ice& Ice::operator=(const Ice &original)
{
	std::cout<<"Ice copy assignment oprator called"<<std::endl;
	if (this != &original)
		this->_type = original.getType();
	return (*this);
}

Ice::Ice(Ice const &original)
{
	std::cout<<"Ice copy constructor called"<<std::endl;
	*this = original;
}

void Ice::use(ICharacter &target)
{
	if (DEBUG)
		std::cout<<"Ice use called"<<std::endl;
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<std::endl;
}