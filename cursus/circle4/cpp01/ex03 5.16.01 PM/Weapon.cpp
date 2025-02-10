/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:20:35 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/17 19:12:41 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{
}
const std::string	&Weapon::getType()
{
	return (_type);
}

void				Weapon::setType(std::string type)
{
	_type = type;
}