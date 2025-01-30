/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:07:18 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 21:41:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "Debug.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria * _inventory[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource & original);
		MateriaSource & operator=(const MateriaSource & original);
		~MateriaSource();
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

