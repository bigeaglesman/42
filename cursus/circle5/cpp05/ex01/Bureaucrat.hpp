/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:09:12 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/27 20:29:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& original);
	public:
		Bureaucrat(const Bureaucrat& original);
		~Bureaucrat();

		Bureaucrat(const std::string& name, const int score);

		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();

		void signForm(Form& form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);