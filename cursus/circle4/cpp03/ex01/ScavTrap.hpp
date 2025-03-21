/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:57:35 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/19 20:02:50 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& original);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& original);
		void attack(const std::string& target);
		void guardGate();
};

#endif