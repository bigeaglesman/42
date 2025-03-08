/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:20:28 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/07 21:19:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
: _name("default"), _req_sign_grade(1), _req_exec_grade(1)
{
	std::cout<<"AForm default constructor called"<<std::endl;
}

AForm::AForm(const AForm& original)
:_name(original.getName()),_is_signed(original.getIsSigned()), _req_sign_grade(original.getReqSignGrade()), _req_exec_grade(original.getReqExecGrade())
{
	std::cout<<"AForm copy constructor called"<<std::endl;
}

AForm& AForm::operator=(const AForm& original)
{
	std::cout<<"AForm copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

AForm::~AForm()
{
	std::cout<<"AForm destructor called"<<std::endl;
}

AForm::AForm(const std::string& name, const int req_sign_gr, const int req_exec_gr)
:_name(name), _is_signed(false), _req_sign_grade(req_sign_gr), _req_exec_grade(req_exec_gr)
{
	if (this->_req_sign_grade < 1 || this->_req_exec_grade < 1)
		throw GradeTooHighException();
	else if (this->_req_sign_grade > 150 || this->_req_exec_grade > 150)
		throw GradeTooLowException();
	std::cout<<"Form name req_grade constructor called"<<std::endl;
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getReqSignGrade() const
{
	return (this->_req_sign_grade);
}

int AForm::getReqExecGrade() const
{
	return (this->_req_exec_grade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_req_sign_grade)
		this->_is_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Too High Grade");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Too Low Grade");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Not Signed Form");
}

bool AForm::getIsSigned() const
{
	return (this->_is_signed);
}

std::ostream& operator<<(std::ostream &out, const AForm &aform)
{
	out<<"Form name: "<<aform.getName()<<", grade required to sign: "<<aform.getReqSignGrade()
	<<", grade required to execute: "<<aform.getReqExecGrade()<<", is signed: "<<aform.getIsSigned();
	return (out);
}