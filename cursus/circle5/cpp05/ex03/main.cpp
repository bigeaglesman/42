/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:08:59 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/08 02:58:45 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main(void)
{
	std::cout<<"##TEST1: Intern test"<<std::endl;

	std::cout<<std::endl<<std::endl;
	Intern intern;
	AForm* shrubberyForm = intern.makeForm("PresidentialPardonForm", "target");
	Bureaucrat bureaucrat("bureaucrat", 1);
	std::cout<<std::endl<<std::endl;

	shrubberyForm->beSigned(bureaucrat);
	shrubberyForm->execute(bureaucrat);
	delete(shrubberyForm);
	std::cout<<std::endl<<std::endl;

	try
	{
		AForm* nonexistentForm = intern.makeForm("NonexistentForm", "target");
	}
	catch(const std::exception& e)
	{
		std::cout<<"Form didnt created: " << e.what() << std::endl;
	}
	
	std::cout<<std::endl<<std::endl;
}