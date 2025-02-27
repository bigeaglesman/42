/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:43:30 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 01:21:46 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm default constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
:AForm(name, 145, 137)
{
	std::cout<<"ShrubberyCreationForm name constructor called"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
	std::cout<<"ShrubberyCreationForm copy assignment operator called"<<std::endl;
	if (this != &original)
		return (*this);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
:AForm(original)
{
	std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm destructor called"<<std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getReqExecGrade())
	{
		std::ofstream tree_file(executor.getName().append("_shrubbery"));
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
	else
		throw GradeTooLowException();
}
