/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:39:32 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/08 03:01:20 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<"Intern default constructor called"<<std::endl;
}

Intern& Intern::operator=(const Intern& original)
{
	std::cout<<"Intern copy assignment operator called"<<std::endl;
	if (&original != this)
		return (*this);
	return (*this);
}

Intern::Intern(const Intern& original)
{
	std::cout<<"Intern copy constructor called"<<std::endl;
	*this = original;
}

Intern::~Intern()
{
	std::cout<<"Intern default destructor called"<<std::endl;
}

static AForm *makePresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}
static AForm *makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
static AForm *makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	std::string formName[] = {"PresidentialPardonForm",
		"RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *(*forms[])(const std::string&) =
	{
		&makePresidential, &makeRobotomy, &makeShrubbery
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == formName[i])
			return (forms[i](target));
	}
	throw NonexistentFormException();
	return(NULL);
}

const char* Intern::NonexistentFormException::what() const throw()
{
	return ("nonexistent Form");
}
