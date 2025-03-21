/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:47:10 by ycho              #+#    #+#             */
/*   Updated: 2025/02/19 20:15:43 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout<<"Default Constructor called"<<std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout<<"ClapTrap Constructor called. ClapTrap's name is "<<this->_name<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	std::cout<<"ClapTrap copy constructor called"<<std::endl;
	*this = original;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"Destructor called. ClapTrap's name is "<<this->_name<<std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}
int ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}
int ClapTrap::getEnergyPoint() const
{
	return (this->_energy_points);
}
int ClapTrap::getAttackDamage() const
{
	return (this->_attack_damage);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
	std::cout<<"ClapTrap copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		this->_name = original.getName();
		this->_hit_points = original.getHitPoints();
		this->_energy_points = original.getEnergyPoint();
		this->_hit_points = original.getHitPoints();
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout<<"ClapTrap "<<this->_name<<" attacks "<<target
			<<", causing "<<this->_attack_damage<<" points of damage!"<<std::endl;
		this->_energy_points--;
	}
	else
		std::cout<<"ClapTrap "<<this->_name<<" can't attack because energy point or hit point is 0"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout<<"ClapTrap "<<this->_name<<" is attacked. ";
	if (this->_hit_points  == 0)
		std::cout<<"But it is already dead. "<<std::endl;
	else 
	{
		std::cout<<std::endl;
		this->_hit_points -= amount;
		if (_hit_points < 0)
			_hit_points = 0;
		std::cout<<"hit points is "<<this->_hit_points<<" now"<<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_hit_points += amount;
		std::cout<<"ClapTrap "<<this->_name<<" is repaired. Hit point is "
			<<this->_hit_points<<" now"<<std::endl;
		this->_energy_points--;
	}
	else
		std::cout<<"ClapTrap "<<this->_name<<" can't be repaired because energy point or hit point is 0"<<std::endl;
}