/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:02:02 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/19 17:06:49 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout<<"FragTrap default constructor called"<<std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	this->setName(name);
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	std::cout<<"FragTrap name constructor called."<<std::endl;
}

FragTrap::FragTrap(const FragTrap& original)
{
	std::cout<<"FragTrap copy constructor called."<<std::endl;
	*this = original;
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap destructor called"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& original)
{
	std::cout<<"FragTrap copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		this->setName(original.getName());
		this->setHitPoint(original.getHitPoints());
		this->setEnergyPoint(original.getEnergyPoint());
		this->setAttackDamage(original.getAttackDamage());
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() > 0  && this->getEnergyPoint() > 0)
		std::cout<<"FragTrap "<<this->getName()<<" high five!"<<std::endl;
	else
		std::cout<<"FragTrap "<<this->getName()<<" can't highfive because energy point or hit point is 0"<<std::endl;
}