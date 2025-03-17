/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:05:53 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/17 16:12:20 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	std::cout<<"##TEST1: subject test"<<std::endl<<std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST2: addNumber iterator test"<<std::endl<<std::endl;
	Span spIter = Span(6);
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(42);
	vec.push_back(24);
	vec.push_back(6);
	vec.push_back(7);
	spIter.addNumber(vec.begin(), vec.end());
	std::vector<int> spanVec = spIter.getArr();
	for (int i = 0;  i < 6; i++)
		std::cout<<spanVec[i]<<" ";
	std::cout<<std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST3: arr short test"<<std::endl<<std::endl;
	try
	{
		Span spShort1 = Span(0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Span spShort2 = Span(1);
		spShort2.addNumber(42);
		spShort2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST4: arr over test"<<std::endl<<std::endl;
	try
	{
		Span spFull = Span(6);
		std::vector<int> vec;
		vec.push_back(4);
		vec.push_back(2);
		vec.push_back(42);
		vec.push_back(24);
		vec.push_back(6);
		vec.push_back(7);
		vec.push_back(8);
		spFull.addNumber(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<<std::endl<<std::endl;
	


	return 0;
}