/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:01:39 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/22 19:43:23 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout<<"Character default constructor called"<<std::endl;
}

Character::Character(const Character& original)
{
	*this = original;
	std::cout<<"Character copy constructor called"<<std::endl;
}

Character::Character(const std::string name)
{
	std::cout<<"Character name parameter constructor called"<<std::endl;
	this->_name = name;
	this->_floor_i = 0;
	for (int i = 0; i < MAX_INDEX; i++)
	{
		this->_inventory[i] = NULL;
		this->_floor[i] = NULL;
	}
}

Character::~Character()
{
	std::cout<<"Character destructor called"<<std::endl;
	for (int i = 0; i < MAX_INDEX; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
	}
}

Character& Character::operator=(const Character& original)
{
	std::cout<<"Character copy assignment operator called"<<std::endl;
	this->_name = original.getName();
	this->_floor_i = original._floor_i;
	for (int i = 0; i < MAX_INDEX; i++)
	{
		if (original._inventory[i] != NULL)
			this->_inventory[i] = original._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
		if (original._floor[i] != NULL)
			this->_floor[i] = original._floor[i]->clone();
		else
			this->_floor[i] = NULL;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria * m)
{
	if (DEBUG)
		std::cout<<"Character "<<this->_name<<" equip called"<<std::endl;
	for (int i = 0; i < MAX_INDEX; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			if (DEBUG)
				std::cout<<"equip "<<m->getType()<<std::endl;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (DEBUG)
		std::cout<<"Character "<<this->_name<<" unequip called"<<std::endl;
	if (this->_inventory[idx] != NULL)
	{
		if (this->_floor_i == 4)
			this->_floor_i = 0;
		if (this->_floor[_floor_i] != NULL)
			delete this->_floor[_floor_i];
		this->_floor[_floor_i] = this->_inventory[idx];
		if (DEBUG)
			std::cout<<"Character "<<this->_name<<" unequip "<<this->_inventory[idx]->getType()<<std::endl;
		this->_inventory[idx] = NULL;
		_floor_i++;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (DEBUG)
		std::cout<<"Character "<<this->_name<<" use Materia in inventory "<<idx<<std::endl;
	if (this->_inventory[idx] != NULL)
	{
		if (DEBUG)
			std::cout<<"Character use "<<this->_inventory[idx]->getType()<<" to "<<target.getName()<<std::endl;
		this->_inventory[idx]->use(target);
	}
}
