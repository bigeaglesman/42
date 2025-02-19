/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:47:11 by ycho              #+#    #+#             */
/*   Updated: 2025/02/19 20:11:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		ClapTrap();
		std::string _name;
		int _hit_points;
		int _energy_points;
		int _attack_damage;
	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& original);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& original);

		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoint() const;
		int getAttackDamage() const;

		void setName(const std::string newName);
		void setHitPoint(const int newHp);
		void setEnergyPoint(const int newEp);
		void setAttackDamage(const int newAd);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif