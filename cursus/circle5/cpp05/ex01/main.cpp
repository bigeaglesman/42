/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:08:59 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/26 03:49:46 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout<<"##TEST1: High exception test"<<std::endl;
	try
	{
		Bureaucrat("HighGrade", 0);
	}
	catch(const std::exception& e)
	{
		std::cout<<"High Grade: "<<e.what()<<std::endl;
	}
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"##TEST2: Low exception test"<<std::endl;
	try
	{
		Bureaucrat("LowGrade", 151);
	}
	catch(const std::exception& e)
	{
		std::cout<<"Low Grade: "<<e.what()<<std::endl;
	}
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"##TEST3: High increase exception test"<<std::endl;
	try
	{
		Bureaucrat grade1 = Bureaucrat("Grade1", 1);
		std::cout<<grade1<<std::endl;
		grade1.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cout<<"Grade Err: "<<e.what()<<std::endl;
	}
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST4: Low decrease exception test"<<std::endl;
	try
	{
		Bureaucrat grade150 = Bureaucrat("Grade150", 150);
		std::cout<<grade150<<std::endl;
		grade150.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cout<<"Grade Err: "<<e.what()<<std::endl;
	}
}