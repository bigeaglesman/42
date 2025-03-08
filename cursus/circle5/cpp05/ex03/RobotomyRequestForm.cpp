/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:51:45 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/08 00:16:01 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestform default constructor called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	std::cout<<"RobotomyRequestform copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
:AForm(original), _target(original.getTarget())
{
	std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:AForm("RobotomyRequestForm", 72, 45)
{
	std::cout<<"RobotomyRequestForm name constructor called"<<std::endl;
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm destructor called"<<std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getReqExecGrade())
		throw GradeTooLowException();
	else if (!this->getIsSigned())
		throw NotSignedException();
	else
	{
		srand(time(0));
		std::cout<<"Bzzzzz... Drilling noises..."<<std::endl;
		if (rand() % 2 == 0)
			std::cout<<"Robotomize "<<this->getTarget()<<" successfully!!!"<<std::endl;
		else
			std::cout<<"Robotomizing"<<this->getTarget()<<" failed..."<<std::endl;
	}
}

