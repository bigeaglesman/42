/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:47:14 by ycho              #+#    #+#             */
/*   Updated: 2025/02/19 17:34:10 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct1("ct1");
	ClapTrap ct2("ct2");
	ClapTrap ct1_copy(ct1);

	ct1.attack("ct2");
	ct2.takeDamage(5);
	ct2.beRepaired(1);
	ct2.takeDamage(10);
	ct2.beRepaired(5);
	for (int i = 0; i < 10; i++)
		ct1.attack("ct2");
	return (0);
}