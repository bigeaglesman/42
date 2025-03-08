/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:52:45 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/07 23:15:56 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout<<"President PardonForm default constructor called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
	std::cout<<"PresidentialPardonForm copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original)
:AForm(original), _target(original.getTarget())
{
	std::cout<<"PresidentialPardonForm copy constructor called"<<std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:AForm("PresidentialPardonForm", 25, 5)
{
	std::cout<<"PresidentialPardonForm name constructor called"<<std::endl;
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm destructor called"<<std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getReqExecGrade())
		throw GradeTooLowException();
	else if (!this->getIsSigned())
		throw NotSignedException();
	else
		std::cout<<this->getTarget()<<" has been pardond by Zaphod Beeblebrox"<<std::endl;
}