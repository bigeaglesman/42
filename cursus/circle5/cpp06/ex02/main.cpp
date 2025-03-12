/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:54:01 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/12 18:12:24 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
	int i = rand() %3;
	if (i == 0)
	{
		std::cout<<"generate A"<<std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout<<"generate B"<<std::endl;
		return new B;
	}
	else if (i)
	{
		std::cout<<"generate C"<<std::endl;
		return new C;
	}
	return (0);
}

void identify(Base* base)
{
	if(dynamic_cast<A*>(base))
		std::cout<<"A";
	else if(dynamic_cast<B*>(base))
		std::cout<<"B";
	else if(dynamic_cast<C*>(base))
		std::cout<<"C";
}

void identify(Base& base)
{
	try
	{
		A &a = dynamic_cast<A&>(base);
		(void)a;
		std::cout<<"A";
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &b = dynamic_cast<B&>(base);
		(void)b;
		std::cout<<"B";
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &c = dynamic_cast<C&>(base);
		(void)c;
		std::cout<<"C";
	}
	catch(const std::exception& e)
	{}
	
}

int main(void)
{
	srand(time(NULL));
	Base* base_ptr = generate();
	Base& base_ref = *base_ptr;
	std::cout<<std::endl;
	std::cout<<"identify ptr: ";
	identify(base_ptr);
	std::cout<<std::endl;
	std::cout<<"identify ref: ";
	identify(base_ref);
	std::cout<<std::endl;
	delete(base_ptr);
	return(0);
}