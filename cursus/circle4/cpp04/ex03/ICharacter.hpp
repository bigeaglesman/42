/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:40:59 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/27 10:26:17 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		ICharacter();
		ICharacter(const std::string name);
		ICharacter(const ICharacter& original);
		virtual ~ICharacter();

		ICharacter& operator=(const ICharacter& original);

		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};