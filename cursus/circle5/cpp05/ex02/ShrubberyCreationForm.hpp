/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:43:28 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 01:21:25 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& original);
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& original);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name);
		void execute(Bureaucrat const & executor) const;
};