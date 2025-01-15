/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:37 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/15 20:25:08 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout<<_name<<" is dead!"<<std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
	std::cout<<"My name is "<<_name<<std::endl;
}

void	Zombie::announce(void)
{
	std::cout<<_name<<" : BraiiiiiiinnnzzzZ..."<<std::endl;
}
