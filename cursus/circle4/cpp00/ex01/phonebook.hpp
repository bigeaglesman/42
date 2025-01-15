/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:05:01 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/15 14:35:11 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <ctime>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define MAX_CONTACT 8

class	PhoneBook
{
	private:
		int			_num_contact;
		int			getOldestContact();
		int			getNumContact();
		void		printTitles();
		void		printText(std::string text, bool newline);
	public:
		PhoneBook();
		~PhoneBook();
		Contact		contact_list[MAX_CONTACT];
		void		addContact();
		void		searchContact();
		std::string	getInput(std::string inputMsg);
};

#endif