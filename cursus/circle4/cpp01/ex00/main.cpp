/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:36:46 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/10 14:58:14 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie stackZom1("stackZom1");
	Zombie* heapZom = newZombie("heapZom");
	heapZom->announce();
	delete(heapZom);
	randomChump("stackZom2");
	return(0);
}