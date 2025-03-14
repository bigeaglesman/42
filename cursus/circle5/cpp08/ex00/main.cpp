/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:42:32 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/15 03:07:12 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec_int;
	vec_int.push_back(2);
	vec_int.push_back(5);
	vec_int.push_back(6);
	vec_int.push_back(20);
	vec_int.push_back(7);
	vec_int.push_back(8);
	try
	{
		std::vector<int>::const_iterator iter1 = easyfind(vec_int, 7);
		std::cout<<*iter1<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout<<std::endl<<std::endl;
	try
	{
		std::vector<int>::iterator iter2 = easyfind(vec_int, 30);
		std::cout<<*iter2<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}