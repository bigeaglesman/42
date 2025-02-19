/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:30 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/19 20:03:02 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout<<"ScavTrap default constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->setName(name);
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	std::cout<<"ScavTrap name constructor called."<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& original)
{
	std::cout<<"ScavTrap copy constructor called."<<std::endl;
	*this = original;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap destructor called"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original)
{
	std::cout<<"ScavTrap copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		this->setName(original.getName());
		this->setHitPoint(original.getHitPoints());
		this->setEnergyPoint(original.getEnergyPoint());
		this->setAttackDamage(original.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() > 0 && this->getHitPoints() > 0)
	{
		std::cout<<"ScavTrap"<<this->getName()<<" attacks "<<target
			<<", causing "<<this->getAttackDamage()<<" points of damage!"<<std::endl;
		this->setEnergyPoint(this->getEnergyPoint()-1);
	}
	else
		std::cout<<this->getName()<<" can't attack because energy point or hit point is 0"<<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap "<<this->getName()<<" is now in GateKeeper mode"<<std::endl;
}


