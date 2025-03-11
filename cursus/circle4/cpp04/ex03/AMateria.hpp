/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:21:28 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/22 18:43:14 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "Debug.hpp"

class ICharacter;

class AMateria
{
	private:
		AMateria(const AMateria& original);
		AMateria& operator=(const AMateria &original);
	protected:
		AMateria();
		std::string _type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};