/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:47:14 by ycho              #+#    #+#             */
/*   Updated: 2025/01/21 22:33:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout<<"ClapTrap Test"<<std::endl;
	std::cout<<"==================================="<<std::endl;
	ClapTrap ct1("ct1");
	ClapTrap ct2("ct2");
	ClapTrap ct1_copy(ct1);
	ClapTrap ct2_copy;

	ct2_copy = ct2;
	ct1.attack("ct2");
	ct2.takeDamage(5);
	ct2.beRepaired(1);
	ct2.takeDamage(10);
	ct2.beRepaired(5);
	for (int i = 0; i < 10; i++)
		ct1.attack("ct2");
	;

	std::cout<<"ScavTrap Test"<<std::endl;
	std::cout<<"==================================="<<std::endl;
	ScavTrap st1("st1");
	ScavTrap st2("st2");
	ScavTrap st1_copy(st1);
	ScavTrap st2_copy;
	st2_copy = st2;
	st1.attack("st2");
	st2.takeDamage(5);
	st2.beRepaired(1);
	st2.takeDamage(10);
	st2.beRepaired(5);
	for (int i = 0; i < 10; i++)
		st1.attack("st2");
	st2.beRepaired(1);
	st1.guardGate();
	return (0);
}