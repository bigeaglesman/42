/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:12:53 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/26 23:28:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// 명시적으로 부모의 매개변수 생성자 호출
Ice::Ice() : AMateria("ice")
{
	std::cout<<"Ice default constuctor called"<<std::endl;
}

Ice::Ice(const Ice &original) : AMateria(original)
{
	std::cout<<"Ice copy constructor called"<<std::endl;
}

Ice::~Ice()
{
	std::cout<<"Ice destructor called"<<std::endl;
}

Ice& Ice::operator=(const Ice &original)
{
	std::cout<<"Ice copy assigment called"<<std::endl;
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<std::endl;
}