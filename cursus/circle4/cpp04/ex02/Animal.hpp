/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:11:20 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 22:55:26 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal& original);
		virtual ~Animal();

		Animal& operator=(const Animal& original);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif