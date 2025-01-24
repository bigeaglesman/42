/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:00:47 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 15:04:19 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout<<"WrongCat default constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat& original)
{
	std::cout<<"WrongCat copy constructor called"<<std::endl;
	*this = original;
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor called"<<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& original)
{
	std::cout<<"WrongCat copy assignment operator called"<<std::endl;
	if (this == &original)
		return (*this);
	this->_type = original._type;
	return (*this);
}


void WrongCat::makeSound(void) const
{
	std::cout<<"WrongCat make sound: WEOM WEOM"<<std::endl;
}