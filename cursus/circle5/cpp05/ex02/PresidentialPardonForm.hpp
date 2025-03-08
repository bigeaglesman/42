/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:52:50 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/07 23:05:19 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& original);
	public:
		PresidentialPardonForm(const PresidentialPardonForm& original);
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;	
};

#endif