/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:00:09 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/18 20:01:15 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
:_name("default"), _is_signed(false), _req_sign_grade(1), _req_exec_grade(1)
{
	std::cout<<"Form default constructor called"<<std::endl;
}

Form::Form(const Form& original)
:_name(original.getName()), _is_signed(false), _req_sign_grade(original.getReqSignGrade()), _req_exec_grade(original.getReqExecGrade())
{
	std::cout<<"Form copy constructor called"<<std::endl;
}

Form& Form::operator=(const Form& original)
{
	std::cout<<"Bureaucrat copy assignment operator called"<<std::endl;
	if (this != &original)
		this->_is_signed = original.getIsSigned();
	return (*this);
}

Form::~Form()
{
	std::cout<<"Form destructor called"<<std::endl;
}

Form::Form(const std::string& name, const int req_sign_gr, const int req_exec_gr)
:_name(name), _is_signed(false), _req_sign_grade(req_sign_gr), _req_exec_grade(req_exec_gr)
{
	if (this->_req_sign_grade < 1 || this->_req_exec_grade < 1)
		throw GradeTooHighException();
	else if (this->_req_sign_grade > 150 || this->_req_exec_grade > 150)
		throw GradeTooLowException();
	std::cout<<"Form name grade constructor called"<<std::endl;
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getReqSignGrade() const
{
	return (this->_req_sign_grade);
}

int Form::getReqExecGrade() const
{
	return (this->_req_exec_grade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_req_sign_grade)
		this->_is_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Too High Grade");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Too Low Grade");
}

bool Form::getIsSigned() const
{
	return (this->_is_signed);
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out<<"Form name: "<<form.getName()<<", grade required to sign: "<<form.getReqSignGrade()
	<<", grade required to execute: "<<form.getReqExecGrade()<<", is signed: "<<form.getIsSigned();
	return (out);
}