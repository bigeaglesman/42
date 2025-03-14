/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:34:03 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/15 00:32:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <ctime>
#include <iostream>

void invertSign(int& a)
{
	a *= -1;
}

template <typename T>
void inc(T& a)
{
	a++;
}

int main(void)
{
	int *arr = new int[20];
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		arr[i] = rand() % 20;

	std::cout<<"original arr: ";
	for (int i = 0; i < 20; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl<<std::endl;

	iter(arr,20,invertSign);
	std::cout<<"inverted arr: ";
	for (int i = 0; i < 20; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl<<std::endl;

	iter(arr, 20, inc<int>);
	std::cout<<"increased arr: ";
	for (int i = 0; i < 20; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl<<std::endl;
	delete[] (arr);
}