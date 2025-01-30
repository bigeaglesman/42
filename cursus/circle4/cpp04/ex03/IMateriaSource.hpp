/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:56:16 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/30 21:41:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>
#include "Debug.hpp"

class IMateriaSource
{
	private:
		IMateriaSource(IMateriaSource & original);
		IMateriaSource & operator=(const IMateriaSource & original);
	protected:
		IMateriaSource();
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria* materia) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};