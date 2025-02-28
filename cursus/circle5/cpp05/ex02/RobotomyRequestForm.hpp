/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:51:43 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/28 09:38:45 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Robotomyrequestform : public AForm
{
	private:
		Robotomyrequestform();
		Robotomyrequestform& operator=(const Robotomyrequestform& original);
	public:
		Robotomyrequestform(const Robotomyrequestform& original);
		~Robotomyrequestform();
		Robotomyrequestform(const std::string& name);
		void execute(Robotomyrequestform const & executor) const;
};

#endif ROBOTOMYREQUESTFORM_HPP