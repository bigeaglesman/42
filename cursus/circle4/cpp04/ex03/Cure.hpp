/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:21:37 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 21:40:50 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "Debug.hpp"

class Cure : public AMateria
{
	private:
		Cure& operator=(const Cure &original);
		Cure(const Cure &original);
	public:
		Cure();
		~Cure();
		Cure* clone() const;
		void use(ICharacter &target);
};