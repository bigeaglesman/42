/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:23:18 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 21:50:57 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout<<"MateriaSource default constructor called"<<std::endl;
}

MateriaSource::MateriaSource(MateriaSource & original)
{
	std::cout<<"MateriaSource copy constructor called"<<std::endl;
	*this = original;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & original)
{
	if (this != &original)
	{
		for (int i = 0; i < 4; i++)
		{
			if (original._inventory[i] != NULL)
				this->_inventory[i] = original._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout<<"MateriaSource copy assignment operator called"<<std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout<<"MateriaSource destructor called"<<std::endl;
}

void MateriaSource::learnMateria(AMateria * materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia->clone();
			break ;
		}
	}
	if (DEBUG)
		std::cout<<"learnMateria called"<<std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			if (this->_inventory[i]->getType() == type)
				return(this->_inventory[i]->clone());
		}
	}
	if (DEBUG)
		std::cout<<"createMateria called"<<std::endl;
	return (0);
}