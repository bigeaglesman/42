/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:21:19 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 17:07:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& original);
		~Brain();

		Brain& operator=(const Brain& original);

		std::string getIdea(const size_t n);
		void setIdea(const size_t n, const std::string idea);
};

#endif