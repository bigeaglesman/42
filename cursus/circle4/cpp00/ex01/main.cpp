/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:41:49 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/13 11:48:27 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while(true)
	{
		std::cout<<"Please input command ADD, SEARCH, EXIT"<<std::endl;
		std::cout<<"Enter command: ";
		if (!std::getline(std::cin, command))
			return (1);
		if (command.compare("ADD") == 0)
		{
			phoneBook.addContact();
		}
		else if (command.compare("SEARCH") == 0)
		{
			phoneBook.searchContact();
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout<<"Wrong command"<<std::endl;
	}
	return (0);
}
