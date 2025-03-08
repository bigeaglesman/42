/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:09:02 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 01:25:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:_name("name")
{
	std::cout<<"Bureaucrat default constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original)
: _name(original.getName()), _grade(original.getGrade())
{
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
	std::cout<<"Bureaucrat copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout<<"Bureaucrat name grade constructor called"<<std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;

}

void Bureaucrat::decGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm& aform) const
{
	try
	{
		aform.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout<<this->getName()<<" couldn't sign "<<aform.getName()<<" because "<<e.what()<<std::endl;
		return ;
	}
	std::cout<<this->getName()<<" signed "<<aform.getName()<<std::endl;
}

void Bureaucrat::executeForm(AForm const & aform)
{
	try
	{
		aform.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout<<this->getName()<<" couldn't execute "<<aform.getName()<<" because "<<e.what()<<std::endl;
		return ;
	}
	std::cout<<this->getName()<<" executed "<<aform.getName()<<std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too High Grade");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too Low Grade");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out<<bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<".";
	return (out);
}