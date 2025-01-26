/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:40:10 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/26 23:28:19 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		Ice& operator=(const Ice &original);

	public:
		Ice();
		Ice(const Ice &original);
		// Ice(std::string const &type);
		~Ice();

		Ice* clone() const;
		void use(ICharacter &target);
};