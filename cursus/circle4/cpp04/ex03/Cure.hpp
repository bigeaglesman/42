/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:21:37 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/26 22:55:09 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		Cure& operator=(const Cure &original);
	public:
		Cure();
		Cure(const Cure &original);
		// Cure(std::string const &type);
		~Cure();

		Cure* clone() const;
		void use(ICharacter &target);
};