/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:40:13 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/10 15:13:46 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	void	setName(std::string name);
	void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif