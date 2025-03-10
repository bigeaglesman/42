/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:08:59 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/27 22:21:01 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout<<"##TEST1: Copy constructor test"<<std::endl;
	Form form1("form1", 10, 15);
	std::cout<<form1<<std::endl;
	Form form1_copy(form1);
	std::cout<<form1_copy<<std::endl;
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"##TEST2: Constructor fail test"<<std::endl;
	try
	{
		Form form2("form2", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cout<<"Form constructor failed : "<< e.what() << std::endl;
	}
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST3: SignForm test"<<std::endl;

	Form form3("form3", 10, 10);
	Bureaucrat bureaucrat1("bureaucrat1", 5);
	bureaucrat1.signForm(form3);
	
	Form form4("form3", 4, 4);
	bureaucrat1.signForm(form4);

	std::cout<<std::endl<<std::endl;


}