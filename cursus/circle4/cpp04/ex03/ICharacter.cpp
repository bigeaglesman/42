/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:28:37 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/27 10:22:05 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout<<"ICharacter default constructor called"<<std::endl;
}

ICharacter::ICharacter(const std::string name)
{
	std::cout<<"ICharacter name parameter constructor called"<<std::endl;
}

ICharacter::ICharacter(const ICharacter& original)
{
	std::cout<<"ICharacter copy constructor called"<<std::endl;
}

ICharacter::~ICharacter()
{
	std::cout<<"ICharacter destructor called"<<std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& original)
{
	std::cout<<"ICharacter copy assignment operator called"<<std::endl;
}
