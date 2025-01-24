/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:54:39 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 21:30:49 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Dog.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& original);
		~Dog();

		Dog& operator=(const Dog& original);

		void makeSound(void) const;
		std::string getIdea(const size_t n) const;
		void setIdea(const size_t n, const std::string idea);
};

#endif