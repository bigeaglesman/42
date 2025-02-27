/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:20:22 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 01:21:36 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		AForm();
	private:
		const std::string _name;
		bool _is_signed;
		const int _req_sign_grade;
		const int _req_exec_grade;
		AForm& operator=(const AForm& original);
	public:
		AForm(const AForm& original);
		virtual ~AForm();

		AForm(const std::string& name, const int req_sign_gr, const int req_exec_gr);
		std::string getName() const;
		int getReqSignGrade() const;
		int getReqExecGrade() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream &out, const AForm &aform);