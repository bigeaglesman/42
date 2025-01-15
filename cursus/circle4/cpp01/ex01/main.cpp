/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:28:21 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/15 20:36:11 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* zomHorde1 = zombieHorde(3, "ZOM1");
	delete[] zomHorde1;
	Zombie* zomHorde2 = zombieHorde(7, "ZOM2");
	delete[] zomHorde2;
	return (0);
}