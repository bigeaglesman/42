/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:51:43 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/07 23:01:59 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& original);
	public:
		RobotomyRequestForm(const RobotomyRequestForm& original);
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

#endif