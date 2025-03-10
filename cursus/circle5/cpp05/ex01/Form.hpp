/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:00:13 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/27 20:24:36 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _req_sign_grade;
		const int _req_exec_grade;
		Form& operator=(const Form& original);
		Form();
	public:
		Form(const Form& original);
		~Form();

		Form(const std::string& name, const int req_sign_gr, const int req_exec_gr);
		std::string getName() const;
		int getReqSignGrade() const;
		int getReqExecGrade() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream &out, const Form &form);