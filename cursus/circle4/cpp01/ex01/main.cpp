/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:28:21 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/10 15:15:00 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* zomHorde1 = zombieHorde(3, "ZOM1");
	for (int i = 0; i < 3; i++)
		zomHorde1[i].announce();
	delete[] zomHorde1;
	Zombie* zomHorde2 = zombieHorde(7, "ZOM2");
	for (int i = 0; i < 7; i++)
		zomHorde2[i].announce();
	delete[] zomHorde2;
	return (0);
}