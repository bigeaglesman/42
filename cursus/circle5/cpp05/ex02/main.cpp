/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:08:59 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/08 00:06:53 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

int main(void)
{
	std::cout<<"##TEST1: Copy constructor test"<<std::endl;

	std::cout<<std::endl<<std::endl;
	ShrubberyCreationForm shrub("target1");
	ShrubberyCreationForm shrub_copy(shrub);
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"shrub"<<std::endl<<shrub<<std::endl;
	std::cout<<"shrub_copy"<<std::endl<<shrub_copy<<std::endl;

	std::cout<<std::endl<<std::endl;
	RobotomyRequestForm robotomy("target2");
	RobotomyRequestForm robotomy_copy(robotomy);
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"robotomy"<<std::endl<<robotomy<<std::endl;
	std::cout<<"robotomy_copy"<<std::endl<<robotomy_copy<<std::endl;

	std::cout<<std::endl<<std::endl;
	PresidentialPardonForm pardon("target3");
	PresidentialPardonForm pardon_copy(pardon);
	std::cout<<std::endl<<std::endl;
	
	std::cout<<"pardon"<<std::endl<<pardon<<std::endl;
	std::cout<<"pardon_copy"<<std::endl<<pardon_copy<<std::endl;
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST2: ShrubberyCreationForm test"<<std::endl;
	Bureaucrat shrubBureaucrat("shrubBureaucrat", 137);
	shrubBureaucrat.executeForm(shrub);
	shrubBureaucrat.signForm(shrub);
	shrubBureaucrat.executeForm(shrub);
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST3: RobotomyRequestForm test"<<std::endl;
	Bureaucrat robotomyBureaucrat("robotomyBureaucrat", 45);
	robotomyBureaucrat.executeForm(robotomy);
	robotomyBureaucrat.signForm(robotomy);
	robotomyBureaucrat.executeForm(robotomy);
	std::cout<<std::endl<<std::endl;

	std::cout<<"##TEST4: PresidentialPardonForm test"<<std::endl;
	Bureaucrat pardonBureaucrat("pardonBureaucrat", 5);
	pardonBureaucrat.executeForm(pardon);
	pardonBureaucrat.signForm(pardon);
	pardonBureaucrat.executeForm(pardon);
	std::cout<<std::endl<<std::endl;



	std::cout<<std::endl<<std::endl;


}