/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:16:53 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 21:30:30 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& original);
		~Cat();

		Cat& operator=(const Cat& original);

		void makeSound(void) const;
		std::string getIdea(const size_t n) const;
		void setIdea(const size_t n, const std::string idea);
};

#endif