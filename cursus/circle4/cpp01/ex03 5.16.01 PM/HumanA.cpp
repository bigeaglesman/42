/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:28:58 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/17 22:17:56 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(&weapon)
{
}
HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout<<_name<<" attacks with their "<<(*_weapon).getType()<<std::endl;
}
