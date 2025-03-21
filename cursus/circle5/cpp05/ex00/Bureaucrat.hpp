/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:09:12 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/18 19:59:53 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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