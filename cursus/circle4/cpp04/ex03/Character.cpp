/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:01:39 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/27 11:48:39 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter()
{
	std::cout<<"Character default constructor called"<<std::endl;
}

Character::Character(const Character& original) : ICharacter(original)
{
	std::cout<<"Character copy constructor called"<<std::endl;
}

Character::Character(const std::string name) : ICharacter(name)
{
	this->_name = name;
	std::cout<<"Character name parameter constructor called"<<std::endl;
}

Character::~Character()
{
	std::cout<<"Character destructor called"<<std::endl;
}

Character& Character::operator=(const Character& original)
{
	this->_name = original.getName();
	for (int i = 0; i < MAX_INDEX; i++)
	{
		if (original._inventory[i] == NULL)

	}
	std::cout<<"Character copy assignment operator called"<<std::endl;
}