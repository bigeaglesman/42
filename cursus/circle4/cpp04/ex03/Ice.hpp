/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:40:10 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 21:40:55 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "Debug.hpp"

class Ice : public AMateria
{
	private:
		Ice& operator=(const Ice &original);
		Ice(const Ice &original);
	public:
		Ice();
		~Ice();
		Ice* clone() const;
		void use(ICharacter &target);
};