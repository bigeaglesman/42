/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:33:12 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/15 00:23:42 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

void leaks()
{
	system("leaks ex02");
}

int main(void)
{
	atexit(leaks);
	Array<int> arr_empty;
	Array<int> arr_num(3);
	Array<int> arr_copy(arr_num);
	std::cout<<std::endl;
	std::cout<<"arr_num: ";
	for (unsigned int i = 0; i < arr_num.size(); i++)
		std::cout<<arr_num[i]<<" "; 
	std::cout<<std::endl<<std::endl;
	arr_num[0] = 4;
	arr_num[1] = 2;
	arr_num[2] = 3;
	std::cout<<"arr_num: ";
	for (unsigned int i = 0; i < arr_num.size(); i++)
		std::cout<<arr_num[i]<<" "; 
	std::cout<<std::endl<<std::endl;
	std::cout<<"arr_copy: ";
	for (unsigned int i = 0; i < arr_copy.size(); i++)
		std::cout<<arr_copy[i]<<" ";
	std::cout<<std::endl<<std::endl;
	const Array<int> arr_copy_const(arr_num);
	std::cout<<"arr_copy_const: ";
	for (unsigned int i = 0; i < arr_copy_const.size(); i++)
		std::cout<<arr_copy_const[i]<<" ";
	std::cout<<std::endl<<std::endl;
	try
	{
		std::cout<<arr_num[4]<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout<<std::endl;
}