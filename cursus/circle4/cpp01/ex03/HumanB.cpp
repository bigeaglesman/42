/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:54:04 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/10 15:27:39 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) 
	: _name(name), _weapon(NULL)
{
}
HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (_weapon == NULL)
		std::cout<<_name<<" has no weapon to attack with"<<std::endl;
	else
		std::cout<<_name<<" attacks with their "<<(*_weapon).getType()<<std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
