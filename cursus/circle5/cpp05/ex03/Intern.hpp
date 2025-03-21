/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:39:04 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/18 20:18:45 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern();
		Intern& operator=(const Intern& original);
		~Intern();
		Intern(const Intern& original);
		AForm *makeForm(const std::string formName, const std::string target);
		class NonexistentFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif