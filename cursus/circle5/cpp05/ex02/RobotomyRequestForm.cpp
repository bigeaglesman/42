/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:51:45 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 10:01:29 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

Robotomyrequestform::Robotomyrequestform()
{
	std::cout<<"RobotomyRequestform default constructor called"<<std::endl;
}

Robotomyrequestform& Robotomyrequestform::operator=(const Robotomyrequestform& original)
{
	std::cout<<"RobotomyRequestform copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

Robotomyrequestform::Robotomyrequestform(const Robotomyrequestform& original)
:AForm(original)
{
	std::cout<<"RobotomyRequestForm copy constructor called"<<std::endl;
}

Robotomyrequestform::Robotomyrequestform(const std::string& name)
:AForm(name, 72, 45)
{
	std::cout<<"RobotomyRequestForm name constructor called"<<std::endl;
}

Robotomyrequestform::~Robotomyrequestform()
{
	std::cout<<"RobotomyRequestForm destructor called"<<std::endl;
}

void Robotomyrequestform::execute(Robotomyrequestform const & executor) const
{
	
}

