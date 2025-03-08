/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:43:30 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/07 22:49:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm default constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout<<"ShrubberyCreationForm name constructor called"<<std::endl;
	this->_target = target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
	std::cout<<"ShrubberyCreationForm copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
:AForm(original), _target(original.getTarget())
{
	std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm destructor called"<<std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getReqExecGrade())
		throw GradeTooLowException();
	else if (!this->getIsSigned())
		throw NotSignedException();
	else
	{
		std::ofstream tree_file(this->getTarget().append("_shrubbery"));
		if (tree_file.is_open())
		{
			tree_file << "      /\\\n";
			tree_file << "     /  \\\n";
			tree_file << "    /____\\\n";
			tree_file << "   /      \\\n";
			tree_file << "  /________\\\n";
			tree_file << "     ||||\n";
			tree_file << "     ||||\n";
			tree_file.close();
		}
		else
		{
			std::cout<<"tree_file open error"<<std::endl;
			return ;
		}
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}
