/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:06:44 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/17 15:47:40 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout<<"Span default constructor called"<<std::endl;
}

Span::~Span()
{
	std::cout<<"Span destructor called"<<std::endl;
}

Span::Span(const Span& original)
{
	std::cout<<"Span copy constructor called"<<std::endl;
	*this = original;
}

std::vector<int> Span::getArr() const
{
	return (this->_arr);
}

unsigned int Span::getArrLen() const
{
	return (this->_arr_len);
}

Span& Span::operator=(const Span& original)
{
	std::cout<<"Span copy assignment operator called"<<std::endl;
	if (this != &original)
	{
		this->_arr_len = original.getArrLen();
		this->_arr = original.getArr();
	}
	return (*this);
}

Span::Span(const unsigned int& len)
{
	std::cout<<"Span length constructor called"<<std::endl;
	if (len == 0)
		throw arrShortException();
	this->_arr_len = len;
}

void Span::addNumber(int n)
{
	if (this->_arr.size() >= this->_arr_len)
		arrOverException();
	this->_arr.push_back(n);
}

void Span::addNumber(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
	if (this->_arr.size() + std::distance(begin, end) > this->_arr_len)
		throw arrOverException();
	this->_arr.insert(this->_arr.end(), begin, end);
}

int Span::shortestSpan() const
{
	if (this->_arr.size() <= 1)
		throw arrShortException();
	std::vector<int> tmp = this->_arr;
	std::sort(tmp.begin(), tmp.end());
	unsigned int sSpan = tmp[1] - tmp[0];
	unsigned int tmpSpan;
	for (unsigned int i = 2; i < this->_arr_len; i++)
	{
		if ((tmpSpan = tmp[i] - tmp[i-1]) < sSpan)
			sSpan = tmpSpan;
	}
	return (sSpan);
}

int Span::longestSpan() const
{
	if (this->_arr.size() <= 1)
		throw arrShortException();
	std::vector<int> tmp = this->_arr;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[this->_arr_len-1] - tmp[0]);
}

const char* Span::arrOverException::what() const throw()
{
	return ("array is full already");
}

const char* Span::arrShortException::what() const throw()
{
	return ("array is too short");
}
