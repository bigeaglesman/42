/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:21:16 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/24 17:11:26 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Brain constructor called"<<std::endl;
}

Brain::Brain(const Brain& original)
{
	std::cout<<"Brain copy constructor called"<<std::endl;
	*this = original;
}

Brain::~Brain()
{
	std::cout<<"Brain destructor called"<<std::endl;
}

Brain& Brain::operator=(const Brain& original)
{
	std::cout<<"Brain copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = original._ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(const size_t n)
{
	return (this->_ideas[n]);
}

void Brain::setIdea(const size_t n, const std::string idea)
{
	this->_ideas[n] = idea;
}