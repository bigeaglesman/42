/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:54:34 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/27 11:37:17 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#define MAX_INDEX 4

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character();
		Character(const Character& original);
		Character(const std::string name);
		~Character();

		Character& operator=(const Character& original);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};