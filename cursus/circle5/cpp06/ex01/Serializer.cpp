/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:18:10 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/12 16:52:09 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout<<"Serializer default constructor called"<<std::endl;
}

Serializer::Serializer(const Serializer& original)
{
	std::cout<<"Serializer copy constructor called"<<std::endl;
	*this = original;
}

Serializer::~Serializer()
{
	std::cout<<"Serializer default destructor called"<<std::endl;
}

Serializer& Serializer::operator=(const Serializer& original)
{
	std::cout<<"Serializer copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}