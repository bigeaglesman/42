/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:08:26 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/20 00:11:55 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP


# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongCat();
		WrongCat(const WrongCat& original);
		~WrongCat();

		WrongCat& operator=(const WrongCat& original);

		void makeSound(void) const;
};

#endif